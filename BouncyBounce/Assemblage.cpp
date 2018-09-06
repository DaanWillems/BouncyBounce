#include "Assemblage.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "UserControlledComponent.h"
#include "SizeComponent.h"
#include <iostream>
#include <SDL.h>

Assemblage::Assemblage()
{

}

Entity Assemblage::createPlayer(SDL_Texture* tex)
{
	Entity player = { Entity() };
	player.positionComponent = new PositionComponent();
	player.textureComponent = new TextureComponent(tex);
	player.userControlledComponent = new UserControlledComponent();
	player.SizeComponent = new SizeComponent();
	player.dragComponent = new DragComponent();

	player.dragComponent->drag = 0.85;
	player.velocityComponent = &VelocityComponent();

	player.positionComponent->x = 300;
	player.positionComponent->y = 200;

	player.velocityComponent->dX = 0;
	player.velocityComponent->dY = 0;
	
	return player;
}

Assemblage::~Assemblage()
{
}
