#pragma once
#include <SDL.h>
#include "Entity.h"
#include "System.h"

class UserInputSystem : public System
{
public:
	UserInputSystem();
	void update();
	~UserInputSystem();
};

