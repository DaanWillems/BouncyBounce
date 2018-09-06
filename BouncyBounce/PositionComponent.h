#pragma once

#include "Component.h"

class PositionComponent: public Component
{
public:
	double x;
	double y;

	PositionComponent();
	~PositionComponent();
};

