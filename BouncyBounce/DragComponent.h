#pragma once

#include "Component.h"
#include <SDL.h>

class DragComponent : public Component
{
public:

	double drag;

	DragComponent();
	~DragComponent();
};

