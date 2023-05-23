#pragma once

#include "Car.h"
#include "RentedCar.h"
#include "Client.h"

#include "list.h"
#include "CarList.h"
#include "ClientList.h"
#include "RentedCarList.h"

class RentCarApp
{
	List* list;
	CarList *cars;
	ClientList *clients;
	RentedCarList *rented_cars;

public:

	RentCarApp(CarList* cars = new CarList, ClientList* clients = new ClientList(), RentedCarList* rented_cars = new RentedCarList());
	~RentCarApp();


	/// Funkcja wyswietla glowne menu programu
	void DisplayMainMenu();
	/// Funkcja wyswietla wszystkie auta dostepne dla klientow
	void DisplayFleet();
	/// Funkcja wyswietla glowne menu Admina
	void DisplayAdminMenu();
	/// Funkcja wyswietla wszystkie auta w systemie oraz pozwala nimi zarz¹dzaæ Adminowi
	void DisplayAllCarsAdmin();
	/// Funkcja wyswietla wszystkie wypozyczone auta w systemie oraz pozwala nimi zarz¹dzac Adminowi
	void DisplayAllRentedCarsAdmin();
	/// Funkcja wyswietla wszystkich klienow w systemie oraz pozwala nimi zarzadzac
	void DisplayAllClientsAdmin();
	/// Funkcja wyswietla ekran pozwalajacy wprowadzic nowe auto do systemu
	void DisplayAddCar();
	/// Funkcja wyswietla ekran pozwalajacy wprowadzic nowego klienta do systemu
	void DisplayAddClient();
	/// Funkcja wyswietla dane kontaktowe
	void DisplayContact();

	/// Funkcja usuwa auto z systemu
	void RemoveCar();
	/// Funkcja usuwa klienta z systemu
	void RemoveClient();
	/// Funkcja wypozycza auto klientowi
	void RentCar();
	/// Funkcja konczy wypozyczenie auta
	void EndRentCar();

	/// Funkcja sprawdza czy plik jest pusty
	bool is_empty(ifstream& pFile);
};

