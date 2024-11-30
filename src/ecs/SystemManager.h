#pragma once
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <typeinfo>
#include <vector>
#include <memory>
#include <cassert>
#include "components.h"
#include "../constants.h"
#include "../util/types.h"


class System {
public:
	std::set<entity_t> entities{};
public:
	virtual ~System() = default;
	virtual void update(float dt) = 0;
	virtual void draw(entity_t e) = 0;
};


class TransformSystem : public System {
public:	
	virtual void update(float dt) override;
	virtual void draw(entity_t e) override;
};


class SpriteSystem : public System {
public:
	virtual void update(float dt) override;
	virtual void draw(entity_t e) override;
};


class SpriteAnimationSystem : public System {
public:
	virtual void update(float dt) override;
	virtual void draw(entity_t e) override;
};



class SystemManager {

private:
	std::unordered_map<component_t, std::unique_ptr<System>> system_map{};
	std::unordered_map<entity_t, std::set<component_t>> entity_to_drawable_components{};
	std::vector<component_t> update_order{};
	std::unordered_set<component_t> drawable_components{};

private:
	template<typename T, typename S>
	void register_component() {
		this->system_map.emplace(typeid(T).name(), std::make_unique<S>());
	}

public:

	SystemManager() {
		// System
		this->register_component<transform_t, TransformSystem>();
		this->register_component<sprite_t, SpriteSystem>();
		this->register_component<sprite_animation_t, SpriteAnimationSystem>();
		assert(this->system_map.size() == NUM_COMPONENTS);

		// Entity to drawable components
		for (entity_t e = 0; e < MAX_ENTITIES; e++) {
			this->entity_to_drawable_components.emplace(e, std::set<entity_t>());
		}

		// Update order
		this->update_order.push_back(typeid(sprite_animation_t).hash_code());
		
	}
	
	template<typename T>
	void insert(const entity_t e) {
		const component_t h = typeid(T).hash_code();
		this->system_map[h]->entities.insert(e);
		if (this->drawable_components.find(h) != this->drawable_components.end()) {
			this->entity_to_drawable_components[e].insert(h);
		}
	}

	template<typename T>
	void erase(const entity_t e) {
		const component_t h = typeid(T).hash_code();
		this->system_map[h]->entities.erase(e);
		this->entity_to_drawable_components[e].erase(h)
	}

	void destroy(const entity_t e) {
		for (auto& pair : this->system_map) {
			pair.second->entities.erase(e);
		}
		this->entity_to_drawable_components[e].clear();
	}

	void clear() {
		for (auto& pair : this->system_map) {
			pair.second->entities.clear();
		}
		for (auto& pair : this->entity_to_drawable_components) {
			pair.second.clear();
		}
	}

};
