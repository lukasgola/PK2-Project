#include <iostream>
#include <fstream>

#include "CarList.h"



using namespace std;

CarList::CarList(){
	first = 0;
}

void CarList::get() {
	Car* temp = first;

	while (temp)
	{
		temp->get();
		temp = temp->next;
	}
}

void CarList::push_back(Car c) {

	Car* p;
	Car* nowy = new Car(c);
	nowy->next = NULL;

	p = first;
	if(p)
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


Car CarList::find(int it) {
	Car* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}



void CarList::remove_obj(int i) {

	Car* temp = first;
	Car* e = first;

	

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
		Car* p;
		p = first;
		if (p)
		{
			first = p->next; 
			delete p;
		}
	}
	else
	{
		Car* p;
		p = first;
		while (p->next != e) p = p->next;
		p->next = e->next;
		delete e;
	}

	
	this->EditFile();
}


void CarList::EditFile() {
	ofstream file;
	file.open("test.txt");

	int counter = 0;
	
	Car* temp = first;

	while (temp)
	{
		file << *temp;
		file << temp->e;
		cout << (!temp->next ? "" : "\n");

		temp = temp->next;
	}

	file.close();

	remove("car_file.txt");
	rename("test.txt", "car_file.txt");
}




Car& CarList::operator[] (const int it) {
	Car* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}



int CarList::new_id() {

	int id = 0;

	Car* temp = first;

	while (temp) {
		id = temp->get_id();
		temp = temp->next;
	}
	return id+1;
}

void CarList::rent(int client_id, int car_id) {

	Car* temp = first;

	while (temp) {
		if (temp->get_id() == client_id)
			temp->rent(car_id);
		temp = temp->next;
	}

}