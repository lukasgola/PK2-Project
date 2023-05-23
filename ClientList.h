#pragma once


#include "Client.h"
#include "List.h"

class ClientList : public List
{
	Client* first;

public:

	ClientList();
	///Funkcja wyswietla wszystkie elementy listy
	void get();
	///Funkcja dodaje nowego klienta do listy
	void push_back(Client cl);
	///Funckja usuwa element listy o podanym id
	void remove_obj(int i);
	///Funkcja zapisuje liste do pliku
	void EditFile();
	///Funkcja znajduje element listy o podanym id
	Client find(int it);
	///Funkcja nadaje id nowo dodanemu klientowi
	int new_id();
	///Funkcja zmienia klientowi id wypozyczonego auta
	void rent(int car_id, int id);

	Client& operator[] (const int it);
};

