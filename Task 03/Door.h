#pragma once
#include "Entity.h"

class Door : public Entity
{
public:
	enum State { IDLE_CLOSED, IDLE_OPEN, OPENING, CLOSING };
	State GetCurrentState() { return currentState; }

	State GetNextDoorState(World & World);
	void DoClosing(float timestep);
	void DoOpening(float timestep);
	void Update(float timestep) override;
	///Virtual so you can have more variety in Door subclasses
	virtual float DoorOpenTime() { return 1.5f; }

	virtual float DoorCloseTime() { return 2; }

	virtual float EntityRange() { return 1; }
	virtual bool EntityInRange(Entity &entity);

private:
	State currentState;
	float animationTime = 0;
}