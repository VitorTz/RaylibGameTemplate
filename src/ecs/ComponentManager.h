#pragma once
#include <unordered_map>
#include <typeinfo>
#include "components.h"
#include "ComponentArray.h"
#include "../util/types.h"


class ComponentManager {

private:
	std::unordered_map<component_t, ComponentArray> component_map{};

private:
	template<typename T>
	void register_component() {
		this->component_map.emplace(typeid(T).hash_code(), sizeof(T));
	}

public:
	ComponentManager();

	template<typename T>
	T* get(const entity_t e) {
		return dynamic_cast<T*>(this->component_map[typeid(T).hash_code()].get(e));
	}

};