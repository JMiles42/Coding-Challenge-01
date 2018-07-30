#pragma once
#include "Entity.h"
#include <vector>

class World
{
public:
	// Get a list of all the characters in the world.
	std::vector<Entity*> const& GetCharacters();

	// Get a list of all the doors in the world.
	std::vector<Entity*> const& GetDoors();
};


