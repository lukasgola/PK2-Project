#include <iostream>
#include <fstream>

#include "RentedCarList.h"


using namespace std;

RentedCarList::RentedCarList() {
	first = 0;
}

void RentedCarList::get() {
	RentedCar* temp = first;

	while (temp)
	{
		temp->get();
		temp = temp->next;
	}
}

void RentedCarList::push_back(Car c, Date s, Date e, int client_id) {

	RentedCar* p;
	RentedCar* nowy = new RentedCar(c, client_id, s, e);
	nowy->next = NULL;

	p = first;
	if (p)
	{
		while (p->next)
		{
			p->get();
			p = p->next;
		}
		p->next = nowy;
	}
	else {
		first = nowy;
	}

	this->EditFile();
}


RentedCar RentedCarList::find(int it) {
	RentedCar* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}



void RentedCarList::remove_obj(int i) {

	RentedCar* temp = first;
	RentedCar* e = first;



	while (temp) {
		if (temp->get_id() == i) {
			e = temp;
			break;
		}
		else {
			temp = temp->next;
		}
	}


	if (first == e) {
		RentedCar* p;
		p = first;
		if (p)
		{
			first = p->next;
			delete p;
		}
	}
	else
	{
		RentedCar* p;
		p = first;
		while (p->next != e) p = p->next;
		p->next = e->next;
		delete e;
	}


	this->EditFile();
}


void RentedCarList::EditFile() {

	ofstream file;
	file.open("test.txt");

	int counter = 0;

	RentedCar* temp = first;

	while(temp) {
		file << *temp;
		file << temp->e;
		file << temp->client_id;
		file << "\n";
		file << temp->start.get_day() << "\n";
		file << temp->start.get_month() << "\n";
		file << temp->start.get_year() << "\n";
		file << temp->end.get_day() << "\n";
		file << temp->end.get_month() << "\n";
		file << temp->end.get_year() << (!temp->next ? "" : "\n");
		
		temp = temp->next;
	}

	file.close();

	remove("rented_file.txt");
	rename("test.txt", "rented_file.txt");
}


RentedCar& RentedCarList::operator[] (const int it) {
	RentedCar* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}