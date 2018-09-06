#include "PhysicsSystem.h"
#include <iostream>


PhysicsSystem::PhysicsSystem()
{
}

void PhysicsSystem::update()
{
	for (unsigned i = 0; i < entities->size(); i++) {

		Entity *e = entities->data()[0];

		if (e->velocityComponent != NULL) {
			std::cout << e->velocityComponent->dX << std::endl;
			e->positionComponent->x += e->velocityComponent->dX;
			e->positionComponent->y += e->velocityComponent->dY;

			if (e->dragComponent != NULL) {
				//Apply drag
				e->velocityComponent->dX = e->velocityComponent->dX * e->dragComponent->drag;
				e->velocityComponent->dY = e->velocityComponent->dY * e->dragComponent->drag;

				if (e->velocityComponent->dX < 0.1 && e->velocityComponent->dX > -0.1)
					e->velocityComponent->dX = 0;

				if (e->velocityComponent->dY < 0.1 && e->velocityComponent->dY > -0.1)
					e->velocityComponent->dY = 0;
			}
		}
	}
}


PhysicsSystem::~PhysicsSystem()
{
}
