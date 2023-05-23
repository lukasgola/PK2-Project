#include <iostream>

#include "Engine.h"

istream& operator >> (istream& s, Engine& e)
{
	s >> e.type >> e.horse_power >> e.fuel_consumption >> e.capacity;

	return s;
}


ostream& operator << (ostream& s, const Engine& e)
{
	s << e.type << "\n" << e.horse_power << "\n" << e.fuel_consumption << "\n" << e.capacity;

	return s;
}

Engine::Engine(string t, int h_p, float f_c, int c)
	:type(t), horse_power(h_p), fuel_consumption(f_c), capacity(c)
{
	
}

void Engine::get() {
	cout << type << "\t" << horse_power << "\t" << fuel_consumption << "\t\t" << capacity << "\t\t";
}

string Engine::get_e_type() {
	return type;
}

int Engine::get_hp() {
	return horse_power;
}

float Engine::get_fl() {
	return fuel_consumption;
}

int Engine::get_capacity() {
	return capacity;
}