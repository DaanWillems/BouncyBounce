#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>
#include "Component.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "UserControlledComponent.h"
#include "SizeComponent.h"
#include "VelocityComponent.h"
#include "DragComponent.h"

class Entity
{
public:
	// https://github.com/CppCon/CppCon2015/blob/master/Tutorials/Implementation%20of%20a%20component-based%20entity%20system%20in%20modern%20C%2B%2B/Implementation%20of%20a%20component-based%20entity%20system%20in%20modern%20C%2B%2B%20-%20Vittorio%20Romeo%20-%20CppCon%202015.pdf
	//List var component? Very ugly!
	
	PositionComponent* positionComponent;
	TextureComponent* textureComponent;
	UserControlledComponent* userControlledComponent;
	SizeComponent* SizeComponent;
	VelocityComponent* velocityComponent;
	DragComponent* dragComponent;

	Entity();
	~Entity();
};

