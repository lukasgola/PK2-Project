#pragma once

#include "RentedCar.h"
#include "List.h"

class RentedCarList : public List
{
	RentedCar* first;

public:

	RentedCarList();

	///Funkcja wyswietla wszystkie elementy listy
	void get();
	///Funkcja dodaje nowe wypozyczone auto do listy
	void push_back(Car c, Date s, Date e, int client_id);
	///Funkcja znajduje element listy o podanym id
	RentedCar find(int it);
	///Funckja usuwa element listy o podanym id
	void remove_obj(int it);
	///Funkcja zapisuje liste do pliku
	void EditFile();

	RentedCar& operator[] (const int it);
};

