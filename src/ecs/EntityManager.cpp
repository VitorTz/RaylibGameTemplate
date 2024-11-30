#include "EntityManager.h"
#include "../constants.h"


EntityManager::EntityManager() {
	for (entity_t e = 0; e < MAX_ENTITIES; e++) {
		this->q.push(e);
	}
}


entity_t EntityManager::create() {
	const entity_t e = this->q.front();
	this->q.pop();
	this->msize++;
	return e;
}


void EntityManager::destroy(const entity_t e) {
	this->q.push(e);
	this->msize--;
}


void EntityManager::clear() {
	this->q = std::queue<entity_t>();
	for (entity_t e = 0; e < MAX_ENTITIES; e++) {
		this->q.push(e);
	}
	this->msize = 0;
}


std::size_t EntityManager::size() const {
	return this->msize;
}