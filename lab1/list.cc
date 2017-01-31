#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {

}

bool List::exists(int d) const {
	Node* ptr = first;
	int val = ptr->value;
	int s = size();
	for (int i = 0; i < s; ++i) {
		if (ptr->value == d) return true;
		// Seg fault here because next doesn't have a value if it's null (last element)
		n = *n.next;
		val = n.value;
	}
	return false;
}

// I would rather have a size variable here but I'm guessing we're
// not supposed to change the header file
int List::size() const {
	Node* ptr = first;
	int size = 0;
	while (ptr != nullptr) {
		ptr = ptr->next;
		++size;
	}
	return size;
}

bool List::empty() const {
	return (size() == 0);
}

void List::insertFirst(int d) {
	// List is empty
	if (first == nullptr) {
		first = new Node(d, nullptr);
	} else { // List not empty
		first = new Node(d, first);
	}
}

void List::remove(int d, DeleteFlag df) {

}

void List::print() const {

}
