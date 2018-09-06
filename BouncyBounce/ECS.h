#pragma once

#include "TextureLoader.h"
#include "Renderer.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "UserControlledComponent.h"
#include "UserInputSystem.h"
#include "SizeComponent.h"
#include "VelocityComponent.h"
#include "Renderer.h"
#include "PhysicsSystem.h"
#include "UserInputSystem.h"
#include <vector>

class ECS
{
public:

	static std::vector<Entity*>entities;

	Renderer renderer;
	PhysicsSystem physicsSystem;
	UserInputSystem inputSystem;

	ECS();
	void update();
	~ECS();
};

