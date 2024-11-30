#pragma once
#include "../util/types.h"


class ComponentArray {

private:
	void* data;
	std::size_t v_size;

public:
	explicit ComponentArray(const std::size_t v_size);
	~ComponentArray();	
	void* get(entity_t e);

};