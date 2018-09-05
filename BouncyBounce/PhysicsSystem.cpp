#include "PhysicsSystem.h"



PhysicsSystem::PhysicsSystem()
{
}

void PhysicsSystem::update()
{
	for (unsigned i = 0; i < entities.size(); i++) {

		Entity* e = entities[i];

		if (e->velocityComponent != NULL) {
			e->positionComponent->x + e->velocityComponent->dX;
			e->positionComponent->y + e->velocityComponent->dY;
		}
	}
}


PhysicsSystem::~PhysicsSystem()
{
}
