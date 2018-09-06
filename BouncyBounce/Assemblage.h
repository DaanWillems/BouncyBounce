#include <SDL.h>
#include "TextureLoader.h"
#include "Entity.h"

#pragma once
class Assemblage
{
public:

	TextureLoader* textureLoader;

	Assemblage();

	Entity createPlayer(SDL_Texture* tex);

	~Assemblage();
};

