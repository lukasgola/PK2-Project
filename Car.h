#pragma once
#include <iostream>
#include <vector>

#include "Engine.h"

using namespace std;

class Car
{

	friend class CarList;
	friend class RentedCarList;

	int id;
	string type;
	string brand;
	string model;
	int production_year;
	int price;
	int rented;
	Car* next;

	Engine e;
	

	

public:

	friend istream& operator >> (istream& s, Car& c);
	friend ostream& operator << (ostream& s, const Car&);

	bool operator == (const Car& c) const { return id == c.id; }
	bool operator != (const Car& c) const { return !operator==(c); }

	//Konstruktory
	Car(int = 0, string = "Type", string = "Brand", string = "Model", int = 2000, int = 200, int = 1, Engine = Engine());
	Car(const Car& c);

	//Destruktory
	~Car();

	//Funkcje sk³adowe

	/// Funkcja wyswietla wszystkie informacje o aucie
	void get();
	/// Funkcja zwraca id auta
	int get_id();
	/// Funkcja zwraca typ auta
	string get_type();
	/// Funkcja zwraca marke auta
	string get_brand();
	/// Funkcja zwraca model auta
	string get_model();
	/// Funkcja zwraca rok produkcji auta
	int get_p_r();
	///Funkcja zwraca cene wypozyczenia na jeden dzien
	int get_price();

	/// Funkcja zwraca czy auto jest wypozyczone
	int get_rented();
	/// Funkcja zmienia stan wypozyczenia auta na przeciwny
	void rent(int i);

	void set_engine(Engine en);

};

