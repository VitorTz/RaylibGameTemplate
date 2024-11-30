#include "TexturePool.h"
#include "hash.h"
#include <cassert>
#include <unordered_map>


static std::unordered_map<std::size_t, Texture2D> pool{};


Texture2D texture_pool_get(const char* filename) {
	const std::size_t h = hash_str(filename);
	if (pool.find(h) == pool.end()) {
		const auto& p = pool.emplace(h, LoadTexture(filename));
		assert(p.first->second.id > 0);
	}
	return pool[h];
}


void texture_pool_destroy(const char* filename) {
	const std::size_t h = hash_str(filename);
	if (pool.find(h) != pool.end()) {
		UnloadTexture(pool[h]);
		pool.erase(h);		
	}
}


void texture_pool_register(const char* filename, Texture2D texture) {
	const std::size_t h = hash_str(filename);
	if (pool.find(h) == pool.end()) {
		pool.emplace(h, std::move(texture));
	}
}


void texture_pool_destroy_all() {
	for (auto& pair : pool) {
		UnloadTexture(pair.second);
	}
	pool.clear();
}


std::size_t texture_pool_size() {
	return pool.size();
}