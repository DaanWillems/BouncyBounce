#include <SDL.h>
#include "TextureLoader.h"
#include "Entity.h"

#pragma once
class Assemblage
{
public:

	TextureLoader* textureLoader;

	Assemblage(TextureLoader* textureLoader);

	Entity* createPlayer();

	Entity* createProjectile(double x, double y, double dX, double dY);

	~Assemblage();
};

