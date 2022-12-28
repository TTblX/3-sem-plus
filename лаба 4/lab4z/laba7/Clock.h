#pragma once
#define nameof(name) #name
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h> 
#include <cstdlib>
#include "Exceptions.h"
using namespace std;

string InputForClock(string);

class Clock
{
	string _brand;
	time_t _time;
public:

	Clock(string brand, time_t time) : _brand(brand), _time(time)
	{
	}

	Clock() = default;

	~Clock() = default;

	string GetBrand()
	{
		return _brand;
	}

	void SetBrand(string brand)
	{
		_brand = brand;
	}

	time_t GetTime()
	{
		return _time;
	}

	void SetTime(time_t time)
	{
		_time = time;
	}

	void Show()
	{
		cout << "Name of brand: " << _brand << endl;
		tm* curTime = localtime(&_time);
		cout << "Time: " << curTime->tm_hour << ":";
		cout << curTime->tm_min << ":";
		cout << curTime->tm_sec << endl;
	}

	friend istream& operator>>(istream&, Clock&);

	bool operator==(const Clock& clock)
	{
		if (_brand == clock._brand)
		{
			return true;
		}

		return false;
	}

	bool operator>(const Clock& clock)
	{
		if (_brand > clock._brand)
		{
			return true;
		}

		return false;
	}

	bool operator<(const Clock& clock)
	{
		if (_brand < clock._brand)
		{
			return true;
		}

		return false;
	}

	friend ostream& operator<<(ostream&, Clock&);

};

istream& operator>>(istream& stream, Clock& clock)
{
	cout << "brand: " << endl;
	stream >> clock._brand;
	cout << "time: " << endl;
	stream >> clock._time;

	return stream;
}

ostream& operator<<(ostream& stream, Clock& clock)
{
	tm* curTime = localtime(&clock._time);
	stream << "brand: " << clock._brand << "   time: " << curTime->tm_hour << ":" << curTime->tm_min << ":" << curTime->tm_sec << endl;

	return stream;
}

class Mechanic : public Clock
{
	string _material;
public:

	Mechanic(string brand, time_t time, string material) : Clock(brand, time), _material(material)
	{
	}

	~Mechanic() = default;

	void SetMaterial(string material)
	{
		_material = material;
	}

	string GetMaterial()
	{
		return _material;
	}

	void Show()
	{
		Clock::Show();
		cout << "Clock's material: " << _material << endl;
	}
};

class Electronic : public Clock
{
	int _amountOfEnergy;
public:

	Electronic(int amountOfEnergy, string brand, time_t time) : Clock(brand, time)
	{
		_amountOfEnergy = amountOfEnergy;
	}

	Electronic(Electronic& other) : Clock(other)
	{

	}

	int GetEnergy()
	{
		return _amountOfEnergy;
	}

	void SetEnergy(int amountOfEnergy)
	{
		if (amountOfEnergy <= 100 && amountOfEnergy >= 0)
		{
			_amountOfEnergy = amountOfEnergy;
		}
		else
		{
			_amountOfEnergy = 0;
		}
	}

	void Show()
	{
		Clock::Show();
		cout << "Energy: " << _amountOfEnergy << "%" << endl;
	}
};

class WallClock : public Mechanic, public Clock
{
	bool _withPendulum;
public:

	WallClock(bool withPendulum, string brand, time_t time, string material) : Mechanic(brand, time, material), Clock(brand, time)
	{
		SetPendulum(withPendulum);
	}

	bool GetPendulum()
	{
		return _withPendulum;
	}

	void SetPendulum(bool withPendulum)
	{
		_withPendulum = withPendulum;
	}

	void Show()
	{
		Mechanic::Show();
		cout << "With pendulum: " << _withPendulum << endl;
	}
};

class Watch : public Mechanic, public Clock
{
	bool _withWinding;
public:

	Watch(bool withWinding, string brand, time_t time, string material) : Mechanic(brand, time, material), Clock(brand, time)
	{
		SetWinding(withWinding);
	}

	void SetWinding(bool withWinding)
	{
		_withWinding = withWinding;
	}

	bool GetWinding()
	{
		return _withWinding;
	}

	void Show()
	{
		Mechanic::Show();
		_withWinding == false ? cout << "With winding : false" << endl :
			cout << "With winding: true" << endl;
	}
};


class FitnessTracker : public Electronic, public Clock
{
	int* _distance;
	int _size;
public:

	FitnessTracker(int* distance, int size, int amountOfEnergy, string brand, time_t time)
		: Electronic(amountOfEnergy, brand, time), Clock(brand, time)
	{
		_size = size;
		_distance = new int[size];
		memcpy(_distance, distance, size * sizeof(int));
	}

	FitnessTracker(FitnessTracker& other) : Electronic(other), Clock()
	{
		_size = other.GetSize();
		_distance = new int[_size];
		memcpy(_distance, other.GetDistanceArray(), _size * sizeof(int));
	}

	int GetSize()
	{
		return _size;
	}

	int* GetDistanceArray()
	{
		return _distance;
	}

	void SetDistanceArray(int* distance, int size)
	{
		delete[] _distance;
		_size = size;
		_distance = new int[size];
		memcpy(_distance, distance, size * sizeof(int));
	}

	void Show()
	{
		Electronic::Show();
		cout << "Covered distance for " << _size << " days: " << SumOfDistance() << " m" << endl;
	}

	int SumOfDistance()
	{
		int sum = 0;

		for (int i = 0; i < this->_size; i++)
		{
			sum += _distance[i];
		}

		return sum;
	}

};
