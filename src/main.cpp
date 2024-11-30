#include <raylib.h>
#include "scene/Scene.h"
#include "util/TexturePool.h"
#include "constants.h"


int main() {
	InitWindow(SCREEN_W, SCREEN_H, WINDOW_TITLE);
	SetTargetFPS(FPS);

	scene_manager_init();

	while (WindowShouldClose() == false) {
		scene_manager_update(GetFrameTime());
		BeginDrawing();
		ClearBackground(BLACK);
		scene_manager_draw();
		EndDrawing();
	}

	texture_pool_destroy_all();
	CloseWindow();
	return 0;
}