#pragma once

#include <vector>
#include "Entity.h"

class System
{
public:

	std::vector<Entity*>*entities;

	System();

	void virtual update();

	~System();
};

