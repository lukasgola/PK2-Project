#include "RentedCar.h"


RentedCar::RentedCar(const Car& car, int c_id, Date s, Date e) : Car(car),  client_id(c_id), start(s), end(e) {
	next = 0;
}


void RentedCar::get() {
	Car::get();
	cout << "\t";
	cout << client_id << "\t\t";
	start.get();
	cout << "\t";
	end.get();
}

int RentedCar::get_client_id() {
	return client_id;
}