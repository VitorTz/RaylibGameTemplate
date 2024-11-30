#pragma once
#include <queue>
#include "../util/types.h"


class EntityManager {

private:
	std::queue<entity_t> q{};
	std::size_t msize{};

public:
	EntityManager();
	entity_t create();
	void destroy(entity_t e);
	void clear();
	std::size_t size() const;

};