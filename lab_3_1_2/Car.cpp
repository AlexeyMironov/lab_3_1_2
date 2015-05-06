#include "stdafx.h"
#include "Car.h"


#include "stdafx.h"
#include "Car.h"
#include <vector>

using namespace std;

CCar::CCar()
: m_isWorking(false)
, m_directionOfMovement(STAND)
, m_currentSpeed(0)
, m_currentTransmission(0)
{
}

CCar::~CCar()
{
}

bool IsSpeedInRange(const int gear, const int speed)
{
	int gearParam = gear;
	if (gear == -1)
	{
		gearParam = 0;
	}

	return (SPEED_LIMIT[gearParam][0] <= speed && SPEED_LIMIT[gearParam][1] >= speed);
}

bool CCar::TurnOnEngine()
{
	if (m_isWorking)
	{
		return !m_isWorking;
	}
	m_isWorking = true;
	return m_isWorking;
}


bool CCar::TurnOffEngine()
{
	if (!m_isWorking)
	{
		return m_isWorking;
	}
	else if (m_isWorking && m_currentSpeed == 0 && m_directionOfMovement == STAND && m_currentTransmission == 0)
	{
		m_isWorking = false;
		return m_isWorking;
	}
	else
	{
		return !m_isWorking;
	}
}


bool CCar::SetGear(const int gear)
{
	if ((gear < -1 || gear > 5) || (!m_isWorking && gear != 0))
	{
		return false;
	}

	switch (gear)
	{
	case -1:
		if (m_currentSpeed == 0 && (m_currentTransmission == 0 || m_currentTransmission == 1))
		{
			m_currentTransmission = gear;
			m_directionOfMovement = STAND;
			return true;
		}
		break;
	case 0:
		m_currentTransmission = gear; //???
		if (m_currentSpeed == 0)
			m_directionOfMovement = STAND;
		return true;
	case 1:
		if ((IsSpeedInRange(1, m_currentSpeed) && m_currentTransmission >= 1) ||
			(m_currentSpeed == 0 && (m_currentTransmission == -1 || m_currentTransmission == 0))) ///??? m_currentTransmission >= 1
		{
			m_currentTransmission = gear;
			if (m_currentSpeed == 0)
			{
				m_directionOfMovement = STAND;
			}
			else
			{
				m_directionOfMovement = FORWARD;
			}
			return true;
		}
		break;

	case 2:
	case 3:
	case 4:
	case 5:
		if (IsSpeedInRange(gear, m_currentSpeed))
		{
			m_currentTransmission = gear;
			m_directionOfMovement = FORWARD; ///????
			return true;
		}
		break;
	default:
		return false;
	}
	return false;
}


bool CCar::SetSpeed(const int speed)
{
	if (speed < 0 || speed > SPEED_LIMIT[SPEED_LIMIT.size() - 1][1] || !m_isWorking)
	{
		return false;
	}
	switch (m_currentTransmission)
	{
	case -1:
		if (IsSpeedInRange(-1, speed))
		{
			if (speed == 0)
			{
				m_directionOfMovement = STAND;  ///???
			}
			else
			{
				m_directionOfMovement = BACK;
			}
			m_currentSpeed = speed;
			return true;
		}

		break;
	case 0:
		if (m_currentSpeed > speed)
		{
			m_currentSpeed = speed;
			if (speed == 0)
				m_directionOfMovement = STAND;
			else
				m_directionOfMovement = FORWARD;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 1:
		if (IsSpeedInRange(1, speed))
		{
			m_currentSpeed = speed;
			if (speed == 0)
				m_directionOfMovement = STAND;
			else
				m_directionOfMovement = FORWARD;
			return true;
		}
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		if (IsSpeedInRange(m_currentTransmission, speed))
		{
			m_currentSpeed = speed;
			return true;
		}
		break;
	default:
		return false;
	}
	return false;
}


bool CCar::GetState()const
{
	return m_isWorking;
}

direction CCar::GetDirection()const
{
	return m_directionOfMovement;
}

int CCar::GetCurrentSpeed()const
{
	return m_currentSpeed;
}

int CCar::GetCurrentGear()const
{
	return m_currentTransmission;
}


