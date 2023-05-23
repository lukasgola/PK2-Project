#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <string>

#include "RentCarApp.h"
#include "Car.h"
#include "RentedCar.h"
#include "Client.h"
#include "Date.h"

using namespace std;



RentCarApp::RentCarApp(CarList *c_l, ClientList *cl_l, RentedCarList *r_c_l) : cars(c_l), clients(cl_l), rented_cars(r_c_l) {

	List* list;

	ifstream car_file("car_file.txt");

	if(!is_empty(car_file)) {
		while (!car_file.eof()) {
			Car c;
			Engine e;
			car_file >> c;
			car_file >> e;
			c.set_engine(e);

			cars->push_back(c);
		}
	}
	car_file.close();

	int client_id;
	int s_day, s_month, s_year;
	int e_day, e_month, e_year;
	
	ifstream rented_file;
	rented_file.open("rented_file.txt");
	if (!is_empty(rented_file)) {
		while (!rented_file.eof()) {

			
			Engine en;
			Car c;
			rented_file >> c;
			rented_file >> client_id;
			rented_file >> en;
			
			rented_file >> s_day >> s_month >> s_year;
			rented_file >> e_day >> e_month >> e_year;

			

			Date s(s_day, s_month, s_year);
			Date e(e_day, e_month, e_year);

			rented_cars->push_back(c, s, e, client_id);
		}
	}
	
	rented_file.close();

	

	int cl_day, cl_month, cl_year;

	ifstream client_file;
	client_file.open("client_file.txt");
	if (!is_empty(client_file)) {
		while (!client_file.eof()) {
			Client cl;
			client_file >> cl;
			client_file >> cl_day;
			client_file >> cl_month;
			client_file >> cl_year;
			
			Date d(cl_day, cl_month, cl_year);
			cl.set_date(d);

			clients->push_back(cl);
		}
	}
	
	client_file.close();
}


RentCarApp::~RentCarApp() {
	delete list;
}



void RentCarApp::DisplayMainMenu() {

	string password = "admin";

	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t         WYPOZYCZALNIA AUT       \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) FLOTA                    |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   2) KONTAKT                  |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   3) ZALOGUJ                  |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t[ESC] Zamknij program            \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";

	char choice = _getch();

	switch (choice) {
	case '1':
		this->DisplayFleet();
		break;

	case '2':
		this->DisplayContact();
		break;

	case '3':
	{
		string pass;
		system("cls");
		cout << "\t\t\t\t_________________________________\n";
		cout << "\t\t\t\t                                 \n";
		cout << "\t\t\t\t         WPROWADZ HASLO          \n";
		cout << "\t\t\t\t                                 \n";
		cout << "\t\t\t\t_________________________________\n";
		cout << "\t\t\t\t                                 \n";
		cout << "\t\t\t\t[ESC] Wstecz                     \n";
		cout << "\t\t\t\t                                 \n";
		cout << "\t\t\t\tHASLO:   ";
		cin >> pass;
		if (pass == password) {
			this->DisplayAdminMenu();
		}
		else {
			cout << "Naura" << endl;
		}
	}

	break;

	case 27:
		exit(0);
		break;

	default:
		system("cls");
		cout << "ERROR" << endl;
	}
}


void RentCarApp::DisplayFleet() {
	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t         WYPOZYCZALNIA AUT       \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t  ID   MARKA\tMODEL\tROK\tSILNIK\tMOC\tSPALANIE\tPOJEMNOSC\tWYP.\tCENA\n";
	
	list = cars;
	list->get();
	
	cout << "\t\t								  \n";
	cout << "\t\t[ESC] Wstecz                     \n";

	char choice = _getch();
	switch (choice) {
	case 27:
		DisplayMainMenu();
		break;

	default:
		DisplayFleet();
	}
}


void RentCarApp::DisplayAllCarsAdmin() {
	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t            LISTA AUT            \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t  ID   MARKA\tMODEL\tROK\tSILNIK\tMOC\tSPALANIE\tPOJEMNOSC\tWYP.\tCENA\n";

	list = cars;
	list->get();

	cout << "\t\t								  \n";
	cout << "\t\t[ESC] Wstecz                     \n";
	cout << "\t\t[1] Wypozycz                     \n";
	cout << "\t\t[2] Dodaj auto                   \n";
	cout << "\t\t[3] Usun auto                    \n";
	cout << "\t\t                                 \n";
	cout << "\t\tWYBIERZ:                       ";
	
	char choice = _getch();
	switch (choice) {
	case '1':
		RentCar();
		break;
	case '2':
		DisplayAddCar();
		break;

	case '3':
		RemoveCar();
		break;

	case 27:
		DisplayAdminMenu();
		break;

	default:
		DisplayAllCarsAdmin();
	}
}


void RentCarApp::DisplayAllRentedCarsAdmin() {
	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t         LISTA WYP. AUT          \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t  ID   MARKA\tMODEL\tROK\tSILNIK\tMOC\tSPALANIE\tPOJEMNOSC\tWYP.\tCENA\tID KLIENTA\tPOCZATEK\tKONIEC\n";

	list = rented_cars;
	list->get();

	cout << "\t\t								  \n";
	cout << "\t\t								  \n";
	cout << "\t\t[ESC] Wstecz                     \n";
	cout << "\t\t[1] Zakoncz wyp.                 \n";
	cout << "\t\t                                 \n";
	cout << "\t\tWYBIERZ:                       ";

	char choice = _getch();
	switch (choice) {
	case '1':
		EndRentCar();
		break;

	case 27:
		DisplayAdminMenu();
		break;

	default:
		DisplayAllRentedCarsAdmin();
	}
}


void RentCarApp::DisplayAdminMenu() {
	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t         WYPOZYCZALNIA AUT       \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) LISTA KLIENTOW           |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   2) LISTA AUT                |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   3) LISTA WYP. AUT           |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t[ESC] Wstecz                     \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";

	char choice = _getch();
	switch (choice) {
	case '1':
		DisplayAllClientsAdmin();
		break;

	case '2':
		DisplayAllCarsAdmin();
		break;
	case '3':
		DisplayAllRentedCarsAdmin();
		break;

	case 27:
		DisplayMainMenu();
		break;

	default:
		DisplayMainMenu();
	}
}


void RentCarApp::DisplayAllClientsAdmin() {
	system("cls");
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t         WYPOZYCZALNIA AUT       \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t  ID   IMIE\tNAZWISKO\tDATA URODZENIA\t\tID AUTA\n";

	list = clients;
	list->get();

	cout << "\t\t[ESC] Wstecz                     \n";
	cout << "\t\t[1] Dodaj klienta                \n";
	cout << "\t\t[2] Usun klienta                 \n";
	cout << "\t\t                                 \n";
	cout << "\t\tWYBIERZ:                       ";

	char choice = _getch();
	switch (choice) {
	case '1':
		DisplayAddClient();
		break;

	case '2':
		RemoveClient();
		break;

	case 27:
		DisplayAdminMenu();
		break;

	default:
		DisplayAllClientsAdmin();
	}
}


void RentCarApp::DisplayAddCar() {
	system("cls");

	string car_type, car_brand, car_model;
	int car_production_year, car_price;

	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t            DODAJ AUTO           \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) TYP NADWOZIA             |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|	  1) SEDAN                    \n";
	cout << "\t\t\t\t|	  2) KOMBI                    \n";
	cout << "\t\t\t\t|	  3) SUV                      \n";
	cout << "\t\t\t\t|	  4) COUPE                    \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";
	char type_choice = _getch();
	switch (type_choice) {
	case '1':
		car_type = "sedan";
		break;
	case '2':
		car_type = "kombi";
		break;
	case '3':
		car_type = "suv";
		break;
	case '4':
		car_type = "coupe";
		break;
	default:
		car_type = "none";
		cout << endl << "Nie ma takiej opcji" << endl;
		break;
	}
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   2) MARKA                    |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> car_brand;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   3) MODEL                    |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> car_model;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   4) ROK PRODUKCJI            |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> car_production_year;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   4) CENA(za dzien)           |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> car_price;


	string engine_type;
	int engine_horse_power;
	float engine_fuel_consumption;
	int engine_capacity;

	cout << "\t\t\t\t|   5) SILNIK                   |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|	  1) DIESEL                   \n";
	cout << "\t\t\t\t|	  2) BENZYNA                  \n";
	cout << "\t\t\t\t|	  3) ELEKTRYK                 \n";
	cout << "\t\t\t\t|	  4) HYBRYDA                  \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";

	type_choice = _getch();
	switch (type_choice) {
	case '1':
		engine_type = "diesel";
		break;
	case '2':
		engine_type = "benzyna";
		break;
	case '3':
		engine_type = "hybryda";
		break;
	case '4':
		engine_type = "elektryk";
		break;
	default:
		engine_type = "none";
		cout << endl << "Nie ma takiej opcji" << endl;
		break;
	}

	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   6) MOC (KM)                 |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> engine_horse_power;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   7) SPALANIE                 |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> engine_fuel_consumption;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   8) POJEMNOSC                |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWPROWADZ...   ";
	cin >> engine_capacity;

	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tCZY CHCESZ DODAC AUTO (t/n): ";

	char car_add;
	cin >> car_add;
	if ((car_add == 't') || (car_add == 'T')) {
		Engine e(engine_type, engine_horse_power, engine_fuel_consumption, engine_capacity);
		Car c(cars->new_id(), car_type, car_brand, car_model, car_production_year, car_price, 0, e);
		cars->push_back(c);
		DisplayAllCarsAdmin();
	}
	else {
		DisplayAllCarsAdmin();
	}
}

void RentCarApp::DisplayAddClient() {
	system("cls");
	string client_name, client_surname;
	int date_day,date_month,date_year;

	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t           DODAJ KLIENTA         \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) IMIE                     |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";
	cin >> client_name;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) NAZWISKO                 |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tWYBIERZ...   ";
	cin >> client_surname;
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|   1) DATA URODZENIA           |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t      DZIEN:               ";
	cin >> date_day;
	cout << "\t\t\t\t      MIESIAC:             ";
	cin >> date_month;
	cout << "\t\t\t\t      ROK:                 ";
	cin >> date_year;
	cout << "\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\tCZY CHCESZ DODAC KLIENTA (t/n):    ";
	char client_add;
	cin >> client_add;
	if ((client_add == 't') || (client_add == 'T')) {
		Date d(date_day, date_month, date_year);
		Client cl (clients->new_id(), client_name, client_surname, 0, d);
		clients->push_back(cl);
		
		DisplayAllClientsAdmin();
	}
	else {
		DisplayAllClientsAdmin();
	}

}

void RentCarApp::DisplayContact() {
	system("cls");

	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t            KONTAKT              \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t_________________________________\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|     ul. Abc, 43-123 Gliwice   |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|     123456789                 |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t|     wypozyczalnia@mail.com    |\n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t                                 \n";
	cout << "\t\t\t\t[ESC] Wstecz                     \n";

	char type_choice = _getch();
	switch (type_choice) {
	case 27:
		DisplayMainMenu();
		break;
	default:
		DisplayMainMenu();
		break;
	}
}


void RentCarApp::RemoveCar() {
	int id;
	cout << "\t\tPodaj ID auta:                 ";
	cin >> id;

	cars->find(id).get();
	cout << "\t\t								  \n";
	cout << "\t\tCzy na pewno chcesz usunac?(t/n): ";
	char car_del;
	cin >> car_del;
	if ((car_del == 't') || (car_del == 'T')) {
		cout << "elo" << endl;
			
		if (cars->find(id).get_rented() == 1) {
			rented_cars->remove_obj(id);
		}	
		cars->remove_obj(id);	
	}
	
	DisplayAllCarsAdmin();
	
	
}

void RentCarApp::RemoveClient() {
	int id;
	cout << "\t\tPodaj ID klienta:                 ";
	cin >> id;

	clients->find(id).get();

	cout << "\t\tCzy na pewno chcesz usunac?(t/n): ";
	char client_del;
	cin >> client_del;
	if ((client_del == 't') || (client_del == 'T')) {
		clients->remove_obj(id);
	}

	DisplayAllClientsAdmin();
}

void RentCarApp::RentCar() {
	int id;
	cout << "\t\tPodaj ID auta:                 ";
	cin >> id;

	if (cars->find(id).get_rented() == 1) {
		cout << "\n";
		cout << "\t\tTo auto nie jest dostepne" << endl;
		cout << "\t\tNacisnij dowolny przycisk...   " << endl;
		cout << "\t\t[ESC] Wstecz                   ";
		char choice = _getch();
		switch (choice) {
		case 27:
			DisplayAdminMenu();
			break;
		default:
			DisplayAllCarsAdmin();
		}
	}
	else {

		int client_id,date_day, date_month, date_year;
		Date start, end;
		system("cls");
		cout << "\t\t  ID   IMIE\tNAZWISKO\tDATA URODZENIA\t\tID AUTA\n";

		list = clients;
		list->get();

		cout << "\n";
		cout << "\t\tPodaj ID klienta :     ";
		cin >> client_id;

		do {

			system("cls");

			cout << "\t\tPodaj date poczatku wypozyczenia :  \n";
			cout << "\n";
			cout << "\t\tDZIEN:               ";
			cin >> date_day;
			cout << "\n";
			cout << "\t\tMIESIAC:             ";
			cin >> date_month;
			cout << "\n";
			cout << "\t\tROK:                 ";
			cin >> date_year;
			cout << "\n";
			cout << "\n";
			start.set(date_day, date_month, date_year);
			cout << "\t\tPodaj date konca wypozyczenia :  \n";
			cout << "\n";
			cout << "\t\tDZIEN:               ";
			cin >> date_day;
			cout << "\n";
			cout << "\t\tMIESIAC:             ";
			cin >> date_month;
			cout << "\n";
			cout << "\t\tROK:                 ";
			cin >> date_year;
			end.set(date_day, date_month, date_year);

		} while (!(start < end));
		system("cls");

		cars->find(id).get();
		cout << "\n\n";
		cout << "\t\t| POCZATEK WYP.: \t";
		start.get();
		cout << "\n\n";
		cout << "\t\t| KONIEC WYP.:   \t";
		end.get();
		cout << "\n";
		
		clients->find(client_id).get();

		cout << "\t\t								  \n";
		cout << "\t\tCzy na pewno chcesz wypozyczyc?(t/n): ";
		char car_rent;
		cin >> car_rent;
		if ((car_rent == 't') || (car_rent == 'T')) {
			cars->rent(id, 1);
			rented_cars->push_back(cars->find(id), start, end, client_id);
			clients->rent(client_id, id);
			clients->EditFile();
			cars->EditFile();
			DisplayAllCarsAdmin();
					
		}
	}

	DisplayFleet();
}

void RentCarApp::EndRentCar() {
	int id;
	cout << "\t\tPodaj ID auta:                 ";
	cin >> id;

	rented_cars->find(id).get();

	cout << "\t\t								  \n";
	cout << "\t\tCzy na pewno chcesz zakonczycz wyp.?(t/n): ";
	char car_rent;
	cin >> car_rent;
	if ((car_rent == 't') || (car_rent == 'T')) {
		clients->rent(rented_cars->find(id).get_client_id(), 0);
		rented_cars->remove_obj(id);
		cars->rent(id, 0);
		cars->EditFile();

	}

	DisplayAllRentedCarsAdmin();
}




bool RentCarApp::is_empty(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}