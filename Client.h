#pragma once
#include <iostream>

#include "Date.h"


using namespace std;

class Client
{

	friend class ClientList;

	int id;
	string name;
	string surname;
	int car_id;
	Date date;
	

	Client* next;


public:

	friend istream& operator >> (istream& s, Client& c);
	friend ostream& operator << (ostream& s, const Client& c);

	//Konstruktory
	Client(int = 0, string = "Kowalski", string="Jan", int=0, Date = Date());
	Client(const Client& c);
	//Destruktory
	~Client();

	//Funkcje sk³adowe

	/// Funkcja wyswietla wszystkie informacje o kliencie
	void get();
	/// Funkcja zwraca id klienta
	int get_id();
	/// Funkcja zwraca imie klienta
	string get_name();
	/// Funkcja zwraca nazwisko klienta
	string get_surname();
	///Funkcja zwraca id wypozyczonego auta
	int get_car_id();
	///Funkcja zmienia id wypozyczonego auta
	void rent(int i);

	void set_date(Date d);
};