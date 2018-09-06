#include "Assemblage.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "UserControlledComponent.h"
#include "SizeComponent.h"
#include <iostream>
#include <SDL.h>

Assemblage::Assemblage(TextureLoader* textureLoader)
{
	this->textureLoader = textureLoader;
}

Entity* Assemblage::createPlayer()
{

	SDL_Texture* tex = this->textureLoader->loadTexture("res/player.bmp");

	Entity* player = new Entity();
	player->positionComponent = new PositionComponent();
	player->textureComponent = new TextureComponent(tex);
	player->userControlledComponent = new UserControlledComponent();
	player->SizeComponent = new SizeComponent();
	player->dragComponent = new DragComponent();

	player->dragComponent->drag = 0.85;
	player->velocityComponent = new VelocityComponent();

	player->positionComponent->x = 20;
	player->positionComponent->y = 20;

	player->velocityComponent->dX = 0;
	player->velocityComponent->dY = 0;
	
	return player;
}

Entity* Assemblage::createProjectile(double x, double y, double dX, double dY)
{

	SDL_Texture* tex = this->textureLoader->loadTexture("res/player.bmp");

	Entity* player = new Entity();
	player->positionComponent = new PositionComponent();
	player->textureComponent = new TextureComponent(tex);
	player->SizeComponent = new SizeComponent();
	player->SizeComponent->height = 20;
	player->SizeComponent->width = 20;
	player->dragComponent = new DragComponent();

	player->dragComponent->drag = 0.98;
	player->velocityComponent = new VelocityComponent();

	player->positionComponent->x = x;
	player->positionComponent->y = y;

	player->velocityComponent->dX = dX*2;
	player->velocityComponent->dY = dY*2;

	return player;
}

Assemblage::~Assemblage()
{
}
