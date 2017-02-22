#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
#include <sstream>
#include <string>

using namespace std;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
void print(const Date& d) {
	cout << d;
}

template <typename T>
string toString(const T& t) {
	string s;
	ostringstream oss;
	oss << t;
	s = oss.str();
	return s;
}

template <typename T>
T string_cast(const string& s) {
	istringstream iss (s);
	T ret;
	iss >> ret;
	if (iss.fail()) {
		throw invalid_argument("Unable to cast");
	}
	return ret;
}

int main() {
	// Check input and output of dates. Uncomment the following when you
	// have added operator>> and operator<<.
	bool cont = true;

	// A4
	double d = 1.234;
	Date today;
	string sd = toString(d);
	string st = toString(today);
	std::cout << sd << " : " << st << '\n';

	// A5
	try {
		int i = string_cast<int>("123");
		// int j = string_cast<int>("sdglksdg");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2015-01-10");
	} catch (std::invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}

	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}

	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	print(d1);
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		print(d1);
		cout << endl;
	}

	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	print(d2);
	cout << endl;
	d2.next();
	print(d2);
	cout << endl;
}
