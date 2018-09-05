#pragma once

#include <SDL.h>
#include <iostream>

class TextureLoader
{
private:
	SDL_Renderer *renderer;

public:
	TextureLoader(SDL_Renderer *ren);
	SDL_Texture* loadTexture(const std::string &file);
	~TextureLoader();
};

