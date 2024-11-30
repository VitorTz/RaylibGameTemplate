#include "ComponentArray.h"
#include <cstdlib>
#include "../constants.h"


ComponentArray::ComponentArray(
	const std::size_t v_size
) {
	this->data = malloc(v_size * MAX_ENTITIES);
	this->v_size = v_size;
}


ComponentArray::~ComponentArray() {
	free(this->data);
}


void* ComponentArray::get(const entity_t e) {
	return ((char*) this->data) + e * this->v_size;
}