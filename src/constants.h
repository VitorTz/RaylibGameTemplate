#pragma once
#include <raylib.h>
#include "scene/SceneID.h"
#include "util/types.h"


constexpr float SCREEN_W{ 1280.0f };
constexpr float SCREEN_H{ 720.0f };
constexpr float SCREEN_CENTERX{ SCREEN_W / 2.0f };
constexpr float SCREEN_CENTERY{ SCREEN_H / 2.0f };
constexpr Vector2 SCREEN_SIZE{ SCREEN_W, SCREEN_H };
constexpr Vector2 SCREEN_CENTER{ SCREEN_CENTERX, SCREEN_CENTERY };
constexpr Rectangle SCREEN_RECT{ 0.0f, 0.0f, SCREEN_W, SCREEN_H };
constexpr char WINDOW_TITLE[]{ "Game Name" };
constexpr unsigned int FPS{ 60 };


constexpr SceneID MAIN_SCENE{ TitleScreenID };
constexpr entity_t MAX_ENTITIES{ 4096 };


