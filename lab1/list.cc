#include <iostream>
#include "list.h"

using namespace std;

List::List() {
	first = nullptr;
}

List::~List() {
	Node* del = first;
	Node* next;
	int s = size();
	for (int i = 0; i < s; ++i) {
		next = del -> next;
		delete del;
		del = next;
	}
}

bool List::exists(int d) const {
	Node* ptr = first;
	int val;
	while (ptr != nullptr) {
		val = ptr -> value;
		ptr = ptr -> next;
		if (val == d) return true;
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
	Node* ptr = first;
	Node* prev_ptr;
	int val;
	int count = 0;
	while (ptr != nullptr) {
		val = ptr -> value;
		switch (df) {
			case List::DeleteFlag::LESS :
			if (val < d) {
				if (count > 0) {
					prev_ptr -> next = ptr -> next;
				} else {
					first = ptr -> next;
				}
				delete ptr;
				// free(ptr);
				// ptr = nullptr;
				return;
			}
			break;
			case List::DeleteFlag::EQUAL :
			if (val == d) {
				if (count > 0) {
					prev_ptr -> next = ptr -> next;
				} else {
					first = ptr -> next;
				}
				delete ptr;
				// free(ptr);
				// ptr = nullptr;
				return;
			}
			break;
			case List::DeleteFlag::GREATER :
			if (val > d) {
				if (count > 0) {
					prev_ptr -> next = ptr -> next;
				} else {
					first = ptr -> next;
				}
				delete ptr;
				// free(ptr);
				// ptr = nullptr;
				return;
			}
			break;
		}
		++count;
		prev_ptr = ptr;
		ptr = ptr -> next;
	}
}

void List::print() const {
	Node* ptr = first;
	int i = 1;
	int val;
	while (ptr != nullptr) {
		val = ptr -> value;
		cout << val;
		cout << ", ";
		++i;
		ptr = ptr -> next;
	}
	cout << endl;
}
