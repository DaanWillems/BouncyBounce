#pragma once

#include "Component.h"
#include <SDL.h>

class VelocityComponent : public Component
{
public:

	double dX;
	double dY;

	VelocityComponent();
	~VelocityComponent();
};

