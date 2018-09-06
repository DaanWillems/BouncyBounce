#include "ECS.h"
#include "Entity.h"
#include "SDL.h"
#include "Renderer.h"
#include "PhysicsSystem.h"
#include "UserInputSystem.h"
#include<vector>

ECS::ECS() {

}

void ECS::update()
{
	renderer.update();
	inputSystem.update();
	physicsSystem.update();
}


ECS::~ECS()
{
}
