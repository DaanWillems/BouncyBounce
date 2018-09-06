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
	for (unsigned i = 0; i < entities->size(); i++) {

		Entity *e = entities->data()[0];

		if (e->textureComponent == NULL) {
			continue;
		}

		SDL_Texture* tex = e->textureComponent->tex;
		SDL_Rect dst;
		dst.x = e->positionComponent->x;
		dst.y = e->positionComponent->y;
		//Query the texture to get its width and height to use
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
		
		if (e->SizeComponent != NULL) {
			dst.h = e->SizeComponent->height;
			dst.w = e->SizeComponent->width;
		}

		SDL_RenderCopy(ren, tex, NULL, &dst);
	
		SDL_RenderPresent(ren);
	}
}


Renderer::~Renderer()
{
}
