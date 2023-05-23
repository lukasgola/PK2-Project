#include <iostream>
#include <fstream>

#include "ClientList.h"


ClientList::ClientList(){
	first = 0;
}

void ClientList::get() {
	Client* temp = first;

	while (temp)
	{
		temp->get();
		temp = temp->next;
	}
}


void ClientList::push_back(Client cl) {

	Client* p;
	Client* nowy = new Client(cl);
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



Client ClientList::find(int it) {
	Client* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}


void ClientList::remove_obj(int i) {

	Client* temp = first;
	Client* e = first;



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
		Client* p;
		p = first;  
		if (p)
		{
			first = p->next;
			delete p;  
		}
	}
	else
	{
		Client* p;
		p = first;
		while (p->next != e) p = p->next;
		p->next = e->next;
		delete e;
	}


	this->EditFile();
}

void ClientList::EditFile() {

	ofstream file;
	file.open("test.txt");

	int counter = 0;

	Client* temp = first;

	while (temp) {
		file << *temp;
		file << temp->date.get_day() << "\n";
		file << temp->date.get_month() << "\n";
		file << temp->date.get_year() << (!temp->next ? "" : "\n");

		
		temp = temp->next;
	}

	file.close();

	remove("client_file.txt");
	rename("test.txt", "client_file.txt");
}

int ClientList::new_id() {

	int id = 0;

	Client* temp = first;

	while (temp) {
		id = temp->get_id();
		temp = temp->next;
	}
	return id + 1;
}

Client& ClientList::operator[] (const int it) {
	Client* temp = first;

	while (temp) {
		if (temp->get_id() == it) {
			return *temp;
		}
		else {
			temp = temp->next;
		}
	}
}

void ClientList::rent(int id, int i) {

	Client* temp = first;

	while (temp) {
		if (temp->get_id() == id)
			temp->rent(i);
		temp = temp->next;
	}

}