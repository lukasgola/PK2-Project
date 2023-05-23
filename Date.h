#pragma once

#include <iostream>


class Date
{

	friend class RentedCar;

	int day;
	int month;
	int year;

public:

	bool operator< (const Date& d);

	Date(int = 1, int = 1, int = 2000);

	void set(int d, int m, int y);
	/// Funkcja wyswietla cala date
	void get();
	/// Funkcja zwraca dzien z daty
	int get_day();
	/// Funkcja zwraca miesiac z daty
	int get_month();
	/// Funkcja zwraca rok z daty
	int get_year();
};
