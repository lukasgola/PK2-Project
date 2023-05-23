#pragma once

#include "Car.h"
#include "Engine.h"
#include "List.h"

class CarList : public List
{
	Car* first;


public:

	CarList();
	///Funkcja wyswietla wszystkie elementy listy
	void get();
	///Funkcja dodaje nowe auto do listy
	void push_back(Car c);

	///Funckja usuwa element listy o podanym id
	void remove_obj(int i);
	///Funkcja zapisuje liste do pliku
	void EditFile();

	///Funkcja znajduje element listy o podanym id
	Car find(int it);

	///Funkcja nadaje id nowo dodanemu aucie
	int new_id();
	///Funkcja zmienia stan wypozyczenia auta
	void rent(int id, int i);

	Car& operator[] (const int it);
};

