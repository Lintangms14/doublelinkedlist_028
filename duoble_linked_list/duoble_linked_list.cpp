#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string nama;
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