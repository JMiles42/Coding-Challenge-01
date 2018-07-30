#pragma once
#include <string>
#include "Float3.h"
#include "World.h"

class Entity
{
public:
	virtual ~Entity() = default;
	World & GetWorld();

	// Returns the current 3D position (in meters) of the entity within the world
	Float3 GetPosition();

	// Returns the current velocity of the character (in meters per second)
	Float3 GetVelocity();

	// Start playing an animation.  Animations stop playing (freezing on their
	// final frame) when complete.
	void StartAnimation(std::string const& anim);
	bool IsAnimationComplete();

	// Get the duration of an animation, in seconds
	float GetAnimationDuration(std::string const& anim);

	// Called every frame with the time elapsed since previous frame, in seconds
	virtual void Update(float timestep) = 0;
};


