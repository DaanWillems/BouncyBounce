#pragma once

#include "Component.h"
#include <SDL.h>

class VelocityComponent : public Component
{
public:

	int dX;
	int dY;

	VelocityComponent();
	~VelocityComponent();
};

