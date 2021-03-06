// CodeChallenge_Task_01.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Timer.h"
#include <vector>
#include <algorithm>
#include <iostream>

/*
Removing from STL vector
There is at least one bug in the following code.  Please fix it for us!
// Modify the timers array in-place to remove all expired timers
void RemoveExpiredTimers(std::vector<Timer> timers)
{
for (auto it = timers.begin(), end = timers.end();
it != end;
++it)
{
if (it->IsExpired())
timers.erase(it);
}
}
 */

void RemoveExpiredTimers_Fixed01(std::vector<Timer>* timers)
{
	for (int i = timers->size() - 1; i >= 0; i--)
	{
		if (timers->at(i).IsExpired())
			timers->erase(timers->begin() + i);
	}

	return;
}

void RemoveExpiredTimers_Fixed02(std::vector<Timer>* timers)
{
	for (int i = 0; i < timers->size(); )
	{
		if (timers->at(i).IsExpired())
		{
			timers->erase(timers->begin() + i);
		}
		else
		{
			++i;
		}
	}
}

void RemoveExpiredTimers_Fixed03(std::vector<Timer>* timers)
{
	for (auto it = timers->begin(); it != timers->end(); ++it)
	{
		if (it->IsExpired())
		{
			it = timers->erase(it);
		}
	}

	return;
}

void RemoveExpiredTimers_Fixed04(std::vector<Timer>* timers)
{
	timers->erase(
		std::remove_if(timers->begin(), timers->end(),
			[](const Timer & t) { return t.IsExpired(); }),
		timers->end());
}

std::vector<Timer> InitVec()
{
	auto rtnVal = std::vector<Timer>(10);
	rtnVal[0] = Timer(false);
	rtnVal[1] = Timer(false);
	rtnVal[2] = Timer(false);
	rtnVal[3] = Timer(true);
	rtnVal[4] = Timer(true);
	rtnVal[5] = Timer(false);
	rtnVal[6] = Timer(true);
	rtnVal[7] = Timer(false);
	rtnVal[8] = Timer(true);
	rtnVal[9] = Timer(false);
	return rtnVal;
}

void PrintVec(std::vector<Timer>* timers)
{
	for (auto value : *timers)
	{
		std::cout << "Expired State: " << value.IsExpired() << "\n";
	}
}

int main()
{
	auto vec = InitVec();
	std::cout << "Full Vector\n";
	PrintVec(&vec);

	RemoveExpiredTimers_Fixed01(&vec);
	std::cout << "RemoveExpiredTimers_Fixed01\n";
	PrintVec(&vec);
	std::getchar();

	vec = InitVec();
	RemoveExpiredTimers_Fixed02(&vec);
	std::cout << "RemoveExpiredTimers_Fixed02\n";
	PrintVec(&vec);
	std::getchar();

	vec = InitVec();
	RemoveExpiredTimers_Fixed03(&vec);
	std::cout << "RemoveExpiredTimers_Fixed03\n";
	PrintVec(&vec);
	std::getchar();

	vec = InitVec();
	RemoveExpiredTimers_Fixed04(&vec);
	std::cout << "RemoveExpiredTimers_Fixed04\n";
	PrintVec(&vec);

	std::cout << "Press Enter to Exit";
	std::getchar();
	return 0;
}
