#include "UserInputSystem.h"
#include <SDL.h>

UserInputSystem::UserInputSystem()
{

}

void UserInputSystem::update() {
	for (unsigned i = 0; i < entities->size(); i++) {
		Entity *e = entities->data()[0];
		if (e->userControlledComponent != NULL) {
			SDL_Event event;
			/*! updates the array of keystates */
			while ((SDL_PollEvent(&event)) != 0)
			{

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
			else if (currentKeyStates[SDL_SCANCODE_SPACE])
			{
				
			}
		}
	}
}



UserInputSystem::~UserInputSystem()
{
}
