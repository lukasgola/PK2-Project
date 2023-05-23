#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "Car.h";

using namespace std;

istream& operator >> (istream& s, Car& c)
{
	s >> c.id >> c.type >> c.brand >> c.model >> c.production_year >> c.price >> c.rented;

	return s;
}

ostream& operator << (ostream& s, const Car& c)
{
	s << c.id << "\n" << c.type << "\n" << c.brand << "\n" << c.model << "\n" << c.production_year << "\n" << c.price << "\n" << c.rented << "\n";

	return s;
}


Car::Car(int c_c, string t, string b, string m, int p_y, int pr, int r, Engine en)
	:id(c_c), type(t), brand(b), model(m), production_year(p_y), price(pr), rented(r), e(en)
{
	next = 0;
}

Car::Car(const Car& c) :id(c.id), type(c.type), brand(c.brand), model(c.model), production_year(c.production_year), price(c.price), rented(c.rented), e(c.e), next(c.next) {

}

Car::~Car() {
	
}

void Car::get() {
	cout << "\t\t\t\t                                                                             \n";
	cout << "\t\t|  " << id << ")  " << brand << "\t" << model << "\t" << production_year << "\t";
	e.get();
	cout << (rented ? "tak" : "nie") << "\t" << price;
}


int Car::get_id() {
	return id;
}
string Car::get_type() {
	return type;
}
string Car::get_brand() {
	return brand;
}
string Car::get_model() {
	return model;
}
int Car::get_p_r() {
	return production_year;
}

int Car::get_price() {
	return price;
}




int Car::get_rented() {
	return rented;
}


void Car::rent(int i) {
	rented = i;
}

void Car::set_engine(Engine en) {
	e = en;
}