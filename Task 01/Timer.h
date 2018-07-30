#pragma once
class Timer
{
public:
	Timer();
	Timer(bool _expiredState);
	~Timer();
	bool IsExpired() const;
private:
	bool expiredState;
};

