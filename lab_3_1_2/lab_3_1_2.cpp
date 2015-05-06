// lab_3_1_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Car.h"


void PrintMenuAndChooseAction(int &menuChoose)
{
	cout << ("1 - Info.\n");
	cout << ("2 - EngineOn.\n");
	cout << ("3 - EngineOff.\n");
	cout << ("4 - SetGear.\n");
	cout << ("5 - SetSpeed.\n");
	cout << ("6 - Exit.\n");
	cout << ("Choose action: ");
	cin >> menuChoose;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CCar car;
	int gear = 0, speed = 0, menuChoose = 0;

	do
	{
		PrintMenuAndChooseAction(menuChoose);
		if (menuChoose == 1)
		{
			if (!car.GetState())
			{
				cout << "Engine state: Off\n";
			}
			else
			{
				cout << "Engine state: On\nGear: " << car.GetCurrentGear()
					<< "\nSpeed: " << car.GetCurrentSpeed() << "\nDirection: ";
				direction carDirection = car.GetDirection();

				if (carDirection == BACK)
					cout << "back\n";
				else if (carDirection == STAND)
					cout << "standing\n";
				else if (carDirection == FORWARD)
					cout << "forward\n";
				else
					cout << "undefinded\n";
			}
		}
		else if (menuChoose == 2)
		{
			bool isOk = car.TurnOnEngine();
			if (!isOk)
			{
				cout << "Can not start engine\n";
			}
		}
		else if (menuChoose == 3)
		{
			bool isOk = car.TurnOffEngine();
			if (!isOk)
			{
				cout << "Can not turn engine off\n";
			}
		}
		else if (menuChoose == 4)
		{
			int newGear;
			cout << "Choose gear : ";
			cin >> newGear;
			bool isOk = car.SetGear(newGear);
			if (!isOk)
			{
				cout << "Can not set gear to " << newGear << "\n";
			}
		}
		else if (menuChoose == 5)
		{
			int newSpeed;
			cout << "Choose speed : ";
			cin >> newSpeed;
			bool isOk = car.SetSpeed(newSpeed);
			if (!isOk)
			{
				cout << "Can not set speed to " << newSpeed << "\n";
			}
		}
	} while (menuChoose != 6);
	return 0;
}

