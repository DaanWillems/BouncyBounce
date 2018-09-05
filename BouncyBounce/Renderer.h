#pragma once
#include <SDL.h>
#include "Entity.h"
#include "System.h"

class Renderer: public System
{
private:
	SDL_Renderer* ren;
public:
	Renderer(SDL_Renderer* ren);
	void update();
	~Renderer();
};

