#pragma once
#include "SceneID.h"


class Scene {
public:
	virtual ~Scene() = default;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
};


class TitleScreen : public Scene {
public:
	TitleScreen();
	void update(float dt) override;
	void draw() override;
};


void scene_manager_init();
void scene_manager_change_scene(SceneID scene_id);
void scene_manager_update(float dt);
void scene_manager_draw();