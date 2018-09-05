#pragma once

#include "Component.h"
#include <SDL.h>

class TextureComponent : public Component
{
public:
	SDL_Texture* tex;

	TextureComponent(SDL_Texture* tex);
	~TextureComponent();
};

