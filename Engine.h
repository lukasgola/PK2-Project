#include <iostream>

using namespace std;

#pragma once
class Engine
{

	friend class Car;

	string type;
	int horse_power;
	float fuel_consumption;
	int capacity;

public:

	friend istream& operator >> (istream& s, Engine& e);
	friend ostream& operator << (ostream& s, const Engine& e);

	Engine(string = "diesel", int = 100, float = 5.0, int = 2000);
	/// Funkcja zwraca wszystkie informacje o silniku
	void get();
	/// Funkcja zwraca typ silnika
	string get_e_type();
	/// Funkcja zwraca moc silnika (KM)
	int get_hp();
	/// Funkcja zwraca spalanie silnika
	float get_fl();
	/// Funkcja zwraca pojemnosc silnika
	int get_capacity();
	
};

