#include <iostream>
#include "list.h"

List::List() {
}

List::~List() {

}

bool List::exists(int d) const {
	Node n = *first;
	int val = n.value;
	for (int i = 0; i < size(); ++i) {
		if (val == d) return true;
		n = *n.next;
		val = n.value;
	}
	return false;
}

// I would rather have a size variable here but I'm guessing we're
// not supposed to change the header file
int List::size() const {
	Node* node_ptr = first;
	int size = 0;
	while (node_ptr != nullptr) {
		Node next_node = *node_ptr;
		node_ptr = next_node.next;
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
		Node n(d, nullptr);
		first = &n;
	}
}

void List::remove(int d, DeleteFlag df) {

}

void List::print() const {
}
