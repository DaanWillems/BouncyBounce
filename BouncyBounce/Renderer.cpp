#include "Renderer.h"
#include <iostream>
#include <SDL.h>
#include "Entity.h"

Renderer::Renderer(SDL_Renderer* ren)
{
	this->ren = ren;
}


void Renderer::update() {
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);
	for (unsigned i = 0; i < entities.size(); i++) {
		SDL_Texture* tex = entities[i]->textureComponent->tex;
		SDL_Rect dst;
		dst.x = entities[i]->positionComponent->x;
		dst.y = entities[i]->positionComponent->y;
		//Query the texture to get its width and height to use
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
		
		if (entities[i]->SizeComponent != NULL) {
			dst.h = entities[i]->SizeComponent->height;
			dst.w = entities[i]->SizeComponent->width;
		}

		SDL_RenderCopy(ren, tex, NULL, &dst);
	
		SDL_RenderPresent(ren);
	}
}


Renderer::~Renderer()
{
}
