#pragma once
#include <SDL.h>
#include "Entity.h"
#include "System.h"
#include "Assemblage.h"

class UserInputSystem : public System
{
public:
	Assemblage* assemblage;
	UserInputSystem(Assemblage* assemblage);
	void update();
	~UserInputSystem();
};

