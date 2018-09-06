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
#include "Assemblage.h"
#include <vector>

UserInputSystem::UserInputSystem(Assemblage* assemblage)
{
	this->assemblage = assemblage;
}

void UserInputSystem::update() {
	for (unsigned i = 0; i < entities->size(); i++) {
		Entity *e = entities->data()[i];
		if (e->userControlledComponent != NULL) {
			SDL_Event event;
			/*! updates the array of keystates */
			while ((SDL_PollEvent(&event)) != 0)
			{
				if (event.type == SDL_KEYDOWN)
				{
					//Select surfaces based on key press
					switch (event.key.keysym.sym)
					{
					case SDLK_SPACE:
						Entity* projectile = this->assemblage->createProjectile(e->positionComponent->x, e->positionComponent->y, e->velocityComponent->dX, e->velocityComponent->dY);
						entities->push_back(projectile);
						break;
					}
				}
			}

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			if (currentKeyStates[SDL_SCANCODE_W])
			{
				e->velocityComponent->dY -= 1;
			}
			else if (currentKeyStates[SDL_SCANCODE_S])
			{
				e->velocityComponent->dY += 1;
			}
			if (currentKeyStates[SDL_SCANCODE_A])
			{
				e->velocityComponent->dX -= 1;
			}
			else if (currentKeyStates[SDL_SCANCODE_D])
			{
				e->velocityComponent->dX += 1;
			}
		}
	}
}



UserInputSystem::~UserInputSystem()
{
}
