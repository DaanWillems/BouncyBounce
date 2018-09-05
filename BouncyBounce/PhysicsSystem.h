#pragma once
#include <SDL.h>
#include "Entity.h"
#include "System.h"

class PhysicsSystem : public System
{
public:
	PhysicsSystem();
	void update();
	~PhysicsSystem();
};

