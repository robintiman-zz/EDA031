#include <iostream>
#include "list.h"

List::List() {
	int size = 0;
}

List::~List() {

}

bool List::exists(int d) const {
	Node n = *first;
	value = n.value;
	for (int i = 0; i < size; ++i) {
		if (value == d) return true;
		n = n.next;
		value = n.value;
	}
	return false;
}

int List::size() const {
	return size;
}

bool List::empty() const {
	return (size == 0);
}

void List::insertFirst(int d) {
}

void List::remove(int d, DeleteFlag df) {
}

void List::print() const {
}
