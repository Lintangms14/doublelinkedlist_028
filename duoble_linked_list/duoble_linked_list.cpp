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

class DuobleLinkedList {
private:
	node* START;
public:

	DuobleLinkedList();
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int rollNo);
	bool listempty();
	void ascending();
	void descending();
	void hapus();
	void searchdata();
};

DuobleLinkedList::DuobleLinkedList() {
	START = NULL;
}

void DuobleLinkedList::addnode() {
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

}