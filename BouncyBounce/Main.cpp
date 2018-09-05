#include <iostream>
#include <SDL.h>
#include "TextureLoader.h"
#include "Renderer.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "UserControlledComponent.h"
#include "UserInputSystem.h"
#include "SizeComponent.h"

void init();

int main(int, char**) {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

	}

	SDL_Window *win = SDL_CreateWindow("BouncyBounce", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Renderer *sdlRen = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (sdlRen == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	Renderer renderer = { Renderer(sdlRen) };
	UserInputSystem inputSystem = { UserInputSystem() };

	TextureLoader texLoader = { TextureLoader(sdlRen) };

	SDL_Texture* tex = texLoader.loadTexture("res/player.bmp");

	Entity e = { Entity() };

	e.positionComponent = &PositionComponent();
	e.textureComponent = &TextureComponent(tex);
	e.userControlledComponent = &UserControlledComponent();
	e.SizeComponent = &SizeComponent();
	e.positionComponent->x = 300;
	e.positionComponent->y = 200;

	renderer.entities.push_back(&e);
	inputSystem.entities.push_back(&e);

	while (true) {
		renderer.update();
		inputSystem.update();
	}

	SDL_Quit();
	return 0;
}

void init() {

}