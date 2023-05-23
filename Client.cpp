#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "Client.h"

using namespace std;


istream& operator >> (istream& s, Client& c)
{
	s >> c.id >> c.name >> c.surname >> c.car_id;

	return s;
}

ostream& operator << (ostream& s, const Client& c)
{
	s << c.id << "\n" << c.name << "\n" << c.surname << "\n" << c.car_id << "\n";

	return s;
}

Client::Client(int c_c, string n, string s_n, int c_id, Date d)
	:id(c_c), name(n), surname(s_n), car_id(c_id), date(d)
{
	next = 0;
}

Client::Client(const Client& c) : id(c.id), name(c.name), surname(c.surname), car_id(c.car_id), date(c.date), next(c.next) {

}

Client::~Client() {
	cout << "Destruktor 1" << endl;
}

void Client::get() {
	cout << "\t\t\t\t                                                                             \n";
	cout << "\t\t|  " << id << ")  " << name << "\t" << surname << "\t\t";
	date.get();
	if (car_id == 0) {
		cout << "\t\t-";
	}
	else {
		cout << "\t\t" << car_id;
	}
	cout << "\t\t\t\t																			  \n";
}

int Client::get_id() {
	return id;
}

string Client::get_name() {
	return name;
}
string Client::get_surname() {
	return surname;
}

int Client::get_car_id() {
	return car_id;
}

void Client::rent(int i) {
	car_id = i;
}

void Client::set_date(Date d) {
	date = d;
}