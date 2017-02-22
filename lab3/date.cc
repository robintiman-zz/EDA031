#include <ctime>  // time and localtime
#include "date.h"
#include <ostream>
#include <istream>
#include <string>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	++day;
	if (day > daysPerMonth[month]) {
		++month;
		day = 1;
	}
	if (month > 12) {
		month = 1;
		++year;
	}
}

istream& operator>>(istream& is, Date& d) {
	string date;
	is >> date;
	if (date == "quit") {
		cin.setstate(ios_base::eofbit);
		return is;
	}
	try {
		d.year = stoi(date.substr(0, 4));
		d.month = stoi(date.substr(5, 2));
		d.day = stoi(date.substr(8, 4));
	} catch (invalid_argument) {
		cin.setstate(ios_base::failbit);
	}
	return is;
}

ostream& operator<<(ostream& os, const Date& d) {
	string year, month, day, date;
	year = to_string(d.year);
	d.month < 10 ? month = "0" + to_string(d.month) : month = to_string(d.month);
	d.day < 10 ? day = "0" + to_string(d.day) : day = to_string(d.day);
	date = year + "-" + month + "-" + day;
	os << date;
	return os;
}
