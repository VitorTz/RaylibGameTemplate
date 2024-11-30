#include "Scene.h"
#include "../constants.h"
#include <memory>


static std::unique_ptr<Scene> scene{};
static bool should_change_scene{};
static SceneID current_scene_id{ MAIN_SCENE };
static SceneID next_scene_id{ MAIN_SCENE };


static void scene_manager_load_next_scene() {
	switch (next_scene_id) {
		case TitleScreenID:
			scene = std::make_unique<TitleScreen>();
			break;		
		default:
			break;
	}
	current_scene_id = next_scene_id;
}


void scene_manager_init() {
	scene_manager_load_next_scene();
}


void scene_manager_change_scene(const SceneID scene_id) {
	should_change_scene = true;
	next_scene_id = scene_id;
}


void scene_manager_update(const float dt) {
	scene->update(dt);
	if (should_change_scene) {
		should_change_scene = false;
		scene_manager_load_next_scene();
	}
}


void scene_manager_draw() {
	scene->draw();
}