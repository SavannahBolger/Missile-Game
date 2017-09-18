/// <summary>
/// author: Savannah Bolger
/// student no: C00215747
/// date: 14/9/2017
/// approx no hours: 4 hrs
/// </summary>

#include <iostream>

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}
}Coordinates;

enum Warhead { Explosive , Nuclear};

typedef struct Enemy
{
	Coordinates coordinates;
}Target;

struct Missile
{
	Warhead payload;
	Coordinates coordinates;
	Target target;
	
	bool armed;

};

void updateTime(int mins, int secs);

int main()
{
	int timeMinutes = 5;
	int timeSeconds = 00;
	int warhead = -1;
	
	std::cout << timeMinutes << ":" << timeSeconds << std::endl;
	std::cout << "Explosive Warhead = 0 \nNuclear Warhead = 1 \nChoose a warhead: ";
	std::cin >> warhead;
	std::cout << std::endl;
	updateTime(timeMinutes, timeSeconds);

	if (warhead < 0 || warhead > 1)
	{
		std::cout << "ERROR Warhead does not exist. Choose existing warhead: ";
		std::cin >> warhead;
		std::cout << std::endl;
	}
	else
	{
		
	}
	system("pause");
	return 0;
}

void updateTime(int mins, int secs)
{
	while (mins != -1 && secs != -1)
	{
		secs--;
		if (secs < 0)
		{
			mins--;
			secs = 59;
		}
		std::cout << mins << ":" << secs << std::endl;

		if (mins == 0 && secs == 0)
		{
			break;
		}
	}
}
