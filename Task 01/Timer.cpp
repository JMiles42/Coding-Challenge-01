#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
	expiredState = false;
}

Timer::Timer(const bool _expiredState) {
	expiredState = _expiredState;
}

Timer::~Timer()
= default;

bool Timer::IsExpired() const { return expiredState; }
