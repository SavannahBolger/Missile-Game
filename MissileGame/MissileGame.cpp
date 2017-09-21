/// <summary>
/// author: Savannah Bolger
/// student no: C00215747
/// date: 14/9/2017
/// approx no hours: 8 hrs
/// </summary>

#include <iostream>
#include <ctime>

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << "{" << x << "," << y << "}" << std::endl;
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
	
	bool armed = false;

	void arm()
	{
		if (armed)
		{
			armed = false;
		}
		else
		{
			armed = true;
		}
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

void chooseWarhead();
void chooseTarget();
void launchCode(bool armed);
void setupTargetAndMissile(Missile missile);

int main()
{
	Missile missile;

	chooseWarhead();
	chooseTarget();
	launchCode(missile.armed);
	setupTargetAndMissile(missile); 

	system("pause");
	return 0;
}

void chooseWarhead()
{
	int warhead;

	std::cout << "Explosive Warhead = 0 \nNuclear Warhead = 1 \nChoose a warhead: ";
	std::cin >> warhead;

	if (warhead <= 0)
	{
		std::cout << "You have chosen the Explosive Warhead." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "You have chosen the Nuclear Warhead." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
}

void chooseTarget()
{
	int target;
	
	std::cout << "1: United States \n2: China \n3: Russia \n4: Australia \n5: Japan \nChoose a target: ";
	std::cin >> target;

	switch (target)
	{
	case 1:
		std::cout << "You're target is United States." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	case 2:
		std::cout << "You're target is China." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	case 3:
		std::cout << "You're target is Russia." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	case 4:
		std::cout << "You're target is Australia." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	case 5:
		std::cout << "You're target is Japan." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	default:
		std::cout << "You're target is China." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	}
}

void launchCode(bool armed)
{
	int launchCode;

	std::cout << "Enter the four digit launch code: ";
	std::cin >> launchCode;
	std::cout << std::endl;

	while (armed == false)
	{
		if (launchCode < 1000 || launchCode > 9999)
		{
			std::cout << "ERROR!! Ineffective launch code." << std::endl;
			std::cout << "Enter the four digit launch code: ";
			std::cin >> launchCode;
		}
		else
		{
			armed = true;
			std::cout << "Missile armed" << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
	}
}

void setupTargetAndMissile(Missile missile)
{
	srand((int)(time(NULL)));
	missile.target.coordinates.x = rand() % 2 + 9;
	missile.target.coordinates.y = 20;
	missile.coordinates.x = 0;
	missile.coordinates.y = 0;

	while (missile.coordinates.x < missile.target.coordinates.x)
	{
		while (missile.coordinates.y < missile.target.coordinates.y)
		{
			missile.update();
		}
	}

	if (missile.coordinates.x == missile.target.coordinates.x && missile.coordinates.y == missile.target.coordinates.y)
	{
		std::cout << "Target has been destroyed" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Target Missed" << std::endl;
		std::cout << "Missile no longer viable" << std::endl;
		std::cout << "Missile has been disarmed" << std::endl;
		std::cout << "Target coordinates: ";
		missile.target.coordinates.print();
		missile.armed = false;
	    std::cout << std::endl;
	}
}


