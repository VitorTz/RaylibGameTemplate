#include "ComponentManager.h"
#include <cassert>


ComponentManager::ComponentManager() {
	assert(NUM_DRAWABLE_COMPONENTS + NUM_UPDATABLE_COMPONENTS <= NUM_COMPONENTS);
	this->register_component<transform_t>();
	assert(this->component_map.size() == NUM_COMPONENTS);
}