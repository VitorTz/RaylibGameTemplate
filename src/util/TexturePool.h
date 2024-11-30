#pragma once
#include <raylib.h>
#include <cstddef>


Texture2D texture_pool_get(const char* filename);

void texture_pool_register(const char* filename, Texture2D texture);

void texture_pool_destroy(const char* filename);

std::size_t texture_pool_size();

void texture_pool_destroy_all();