#include <iostream>

#include "Date.h"

using namespace std;


bool Date::operator< (const Date& d) {
	if (year < d.year) {
		return true;
	}
	else if (year == d.year) {
		if (month < d.month) {
			return true;
		}
		else if (month = d.month) {
			if (day < d.day) {
				return true;
			}
		}
	}

    return false;
}




Date::Date(int d, int m, int y) : day(d), month(m), year(y) {

}

void Date::get() {
	cout << day << "/" << month << "/" << year;
}

int Date::get_day() {
	return day;
}

int Date::get_month() {
	return month;
}

int Date::get_year() {
	return year;
}

void Date::set(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
