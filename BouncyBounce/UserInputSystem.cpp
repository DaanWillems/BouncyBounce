#include "UserInputSystem.h"
#include <SDL.h>

UserInputSystem::UserInputSystem()
{

}

void UserInputSystem::update() {
	for (unsigned i = 0; i < entities.size(); i++) {
		if (entities[i]->userControlledComponent != NULL) {
			SDL_Event e;
			/*! updates the array of keystates */
			while ((SDL_PollEvent(&e)) != 0)
			{

			}

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			if (currentKeyStates[SDL_SCANCODE_W])
			{
				entities[i]->positionComponent->y -= 2;
			}
			else if (currentKeyStates[SDL_SCANCODE_S])
			{
				entities[i]->positionComponent->y += 2;
			}
			if (currentKeyStates[SDL_SCANCODE_A])
			{
				entities[i]->positionComponent->x -= 2;
			}
			else if (currentKeyStates[SDL_SCANCODE_D])
			{
				entities[i]->positionComponent->x += 2;
			}

		}
	}
}



UserInputSystem::~UserInputSystem()
{
}
