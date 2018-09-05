#pragma once

#include "Component.h"
#include <SDL.h>
class SizeComponent : public Component
{
public:
	int width;
	int height;

	SizeComponent();
	~SizeComponent();
};

