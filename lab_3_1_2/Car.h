#pragma once
#include <vector>
using namespace std;

enum direction
{
	BACK = -1, STAND = 0, FORWARD = 1
};

const vector<const vector<const int>> SPEED_LIMIT = {
	{ 0, 20 },
	{ 0, 30 },
	{ 20, 50 },
	{ 30, 60 },
	{ 40, 90 },
	{ 50, 150 }
};


class CCar
{
public:
	CCar();
	~CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const int gear);
	bool SetSpeed(const int speed);
	bool GetState()const;
	direction GetDirection()const;
	int GetCurrentSpeed()const;
	int GetCurrentGear()const;

private:
	bool m_isWorking;
	direction m_directionOfMovement;
	int m_currentSpeed;
	int m_currentTransmission;
};

