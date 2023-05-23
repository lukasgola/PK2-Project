#pragma once

#include "Car.h"
#include "Date.h"

class RentedCar :public Car
{
	friend class RentedCarList;

	int client_id;
	Date start;
	Date end;

	RentedCar* next;

public:
	RentedCar(const Car& car, int = 0, Date = Date(), Date = Date());
	/// Funkcja wyswietla wszystkie informacje o wypozycznym samochodzie
	void get();
	/// Funkcja zwraca id klienta, ktory wypozyczyl auto
	int get_client_id();

};

