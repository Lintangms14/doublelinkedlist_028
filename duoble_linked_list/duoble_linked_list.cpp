#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {
private:
	node* START;
public:

	DoubleLinkedList();
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int rollNo);
	bool listempty();
	void ascending();
	void descending();
	void hapus();
	void searchdata();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addnode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin.ignore();
	getline(cin, nm);
	node* newnode = new node();
	newnode->noMhs = nim;
	newnode->name = nm;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = START;
		if (START != NULL)
			START->prev = newnode;
		newnode->prev = NULL;
		START = newnode;
		return;
	}
	node* current = START;
	while (current->next != NULL && nim > current->next->noMhs)
		current = current->next;

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newnode->next = current->next;
	newnode->prev = current;
	if (current->next != NULL)
		current->next->prev = newnode;
	current->next = newnode;
}

bool DoubleLinkedList::search(int rollNo, node** previous, node** current) {
	*previous = *current = START;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deletenode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;

	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::listempty() {
	return (START == NULL);
}

void DoubleLinkedList::ascending() {
	if (listempty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		node* currentnode = START;
		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void DoubleLinkedList::descending() {
	if (listempty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		node* currentnode = START;
		while (currentnode->next != NULL)
			currentnode = currentnode->next;

		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listempty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deletenode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted" << endl;
}
void DoubleLinkedList::searchdata() {
	if (listempty() == true) {
		cout << "\nList is empty" << endl;

	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

