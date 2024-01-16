#include <iostream>
#include <map>
using namespace std;


class Combat_Unit abstract
{
protected:
	char sprite;
	int moveSpeed;
	int power;
public:
	virtual void Show(int x, int y) abstract;
};

class Light_Infantry : public Combat_Unit
{
public:
	Light_Infantry()
	{
		sprite = 'A';
		moveSpeed = 20;
		power = 10;
	}
	void Show(int x, int y) override
	{
		cout << "Light_Infantry: " << sprite << ' ' << moveSpeed << ' ' << power << " Position: " << x << ' ' << y << endl;
	}
};

class Transport_Vehicles : public Combat_Unit
{
public:
	Transport_Vehicles()
	{
		sprite = 'C';
		moveSpeed = 70;
		power = 0;
	}
	void Show(int x, int y) override
	{
		cout << "Transport_Vehicles: " << sprite << ' ' << moveSpeed << ' ' << power << " Position: " << x << ' ' << y << endl;
	}
};

class Heavy_Ground_Combat_Vehicles : public Combat_Unit
{
public:
	Heavy_Ground_Combat_Vehicles()
	{
		sprite = 'T';
		moveSpeed = 15;
		power = 150;
	}
	void Show(int x, int y) override
	{
		cout << "Heavy_Ground_Combat_Vehicles: " << sprite << ' ' << moveSpeed << ' ' << power << " Position: " << x << ' ' << y << endl;
	}
};

class Light_Ground_Combat_Vehicles : public Combat_Unit
{
public:
	Light_Ground_Combat_Vehicles()
	{
		sprite = 'G';
		moveSpeed = 50;
		power = 30;
	}
	void Show(int x, int y) override
	{
		cout << "Light_Ground_Combat_Vehicles: " << sprite << ' ' << moveSpeed << ' ' << power << " Position: " << x << ' ' << y << endl;
	}
};

class Aircraft : public Combat_Unit
{
public:
	Aircraft()
	{
		sprite = 'F';
		moveSpeed = 300;
		power = 100;
	}
	void Show(int x, int y) override
	{
		cout << "Aircraft: " << sprite << ' ' << moveSpeed << ' ' << power << " Position: " << x << ' ' << y << endl;
	}
};

class Millitary_Base
{
private:
	map<char, Combat_Unit*> combat_units;
public:
	Combat_Unit* GetCharacter(char key)
	{
		Combat_Unit* combat_unit = combat_units[key];
		if (combat_unit == nullptr)
		{
			switch (key)
			{
			case 'L':
				combat_unit = new Light_Infantry();
				break;
			case 'C':
				combat_unit = new Transport_Vehicles();
				break;
			case 'T':
				combat_unit = new Heavy_Ground_Combat_Vehicles();
				break;
			case 'G':
				combat_unit = new Light_Ground_Combat_Vehicles();
				break;
			case 'F':
				combat_unit = new Aircraft();
				break;
			}
			combat_units[key] = combat_unit;
		}
		return combat_unit;
	}
};

int main()
{
	
	string units = "LCTGFFGLCCLT";

	Millitary_Base* combat_units = new Millitary_Base();

	int x = 0;
	int y = 0;

	for(int i = 0; i < units.length(); i++)
	{
		Combat_Unit* combat_unit = combat_units->GetCharacter(units[i]);
		combat_unit->Show(x++, y++);
	}

	system("pause");
}
