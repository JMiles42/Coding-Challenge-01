#include "stdafx.h"
#include "Door.h"

Door::State Door::GetNextDoorState(World &World)
{
	for (auto Character : World.GetCharacters())
	{
		if (GetPosition().Distance(Character->GetPosition()) >= 1)
		{
			return OPENING;
		}
	}

	return CLOSING;
}

void Door::DoClosing(const float timestep)
{
	animationTime += timestep;
	const auto totalTime = DoorCloseTime();
	if(animationTime >= totalTime)
	{
		currentState = IDLE_CLOSED;
		animationTime = 0;
	}
	else
	{
		currentState = CLOSING;
	}
}

void Door::DoOpening(const float timestep)
{
	animationTime += timestep;
	const auto totalTime = DoorOpenTime();
	if (animationTime >= totalTime)
	{
		currentState = IDLE_OPEN;
		animationTime = 0;
	}
	else
	{
		currentState = OPENING;
	}
}

void Door::Update(float timestep)
{
	auto world = GetWorld();

	switch (currentState)
	{
	case CLOSING:
		break;
	case OPENING:
		break;
	case IDLE_OPEN:
	case IDLE_CLOSED:
		currentState = GetNextDoorState(world);

		break;
	default:
		break;
	}

	if (currentState == CLOSING)
	{
		DoClosing(timestep);
	}
	else if (currentState == OPENING)
	{
		DoOpening(timestep);
	}

	auto state = GetNextDoorState(world);
}

bool Door::EntityInRange(Entity &entity) {
	///TODO: self ignoring logic
	//if(entity is Door)
	return GetPosition().Distance(entity.GetPosition()) >= 1;
}

