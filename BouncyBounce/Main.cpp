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
#include "VelocityComponent.h"
#include "PhysicsSystem.h"

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
	PhysicsSystem physicsSystem = { PhysicsSystem() };

	TextureLoader texLoader = { TextureLoader(sdlRen) };

	SDL_Texture* tex = texLoader.loadTexture("res/player.bmp");

	Entity player = { Entity() };
	player.positionComponent = &PositionComponent();
	player.textureComponent = &TextureComponent(tex);
	player.userControlledComponent = &UserControlledComponent();
	player.SizeComponent = &SizeComponent();

	player.velocityComponent = &VelocityComponent();

	player.positionComponent->x = 300;
	player.positionComponent->y = 200;

	player.velocityComponent->dX = 1;
	player.velocityComponent->dY = 1;

	renderer.entities.push_back(&player);
	inputSystem.entities.push_back(&player);
	physicsSystem.entities.push_back(&player);

	while (true) {
		renderer.update();
		inputSystem.update();
		physicsSystem.update();
	}

	SDL_Quit();
	return 0;
}

void init() {

}