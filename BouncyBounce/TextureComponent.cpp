#include "TextureComponent.h"
#include <SDL.h>


TextureComponent::TextureComponent(SDL_Texture* tex)
{
	this->tex = tex;
}


TextureComponent::~TextureComponent()
{
}
