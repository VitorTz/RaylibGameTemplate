#pragma once
#include <raylib.h>
#include "../util/TexturePool.h"
#include "../util/types.h"


constexpr component_t NUM_COMPONENTS{ 3 };
constexpr component_t NUM_DRAWABLE_COMPONENTS{ 2 };
constexpr component_t NUM_UPDATABLE_COMPONENTS{ 1 };


typedef struct transform {
	Vector2 pos{};
	Vector2 size{};
	zindex_t zindex{};
	transform() = default;
	explicit transform(const zindex_t zindex) : zindex(zindex) { }
} transform_t;


typedef struct sprite {
	Texture2D texture{};
	sprite() = default;
	explicit sprite(const char* filename) : texture(texture_pool_get(filename)) { }
} sprite_t;


typedef struct sprite_animation {
	Texture2D texture{};
	Rectangle rect{};
	std::uint8_t index{};
	std::uint8_t max_index{};
	std::uint8_t frame{};	
	std::uint8_t rows{};
	std::uint8_t cols{};
	float speed{};
	sprite_animation(
		const char* filename,
		const float width,
		const float height,
		const float speed,
		const std::uint8_t rows,
		const std::uint8_t cols
	) : texture(texture_pool_get(filename)),
		rect({0.0f, 0.0f, width, height}),
	    max_index(rows * cols),
	    rows(rows),
		cols(cols) { }
} sprite_animation_t;