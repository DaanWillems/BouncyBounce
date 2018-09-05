#include "TextureLoader.h"
#include <SDL.h>
#include <iostream>


TextureLoader::TextureLoader(SDL_Renderer *ren)
{
	this->renderer = ren;
}

/*

	std::string imagePath = "res/lena_gray.bmp";
	SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
	if (bmp == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

*/

SDL_Texture* TextureLoader::loadTexture(const std::string &file) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	//Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr) {
			std::cout << "Error loading surface" << std::endl;
		}
	}
	else {
		std::cout << "Error loading image" << std::endl;
	}
	return texture;
}

TextureLoader::~TextureLoader()
{
}
