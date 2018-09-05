#pragma once

#include "Component.h"

class PositionComponent: public Component
{
public:
	int x;
	int y;

	PositionComponent();
	~PositionComponent();
};

