#include<iostream>
using namespace std;

struct node {
	int nomhs;
	string name;
	node* next;
};

node* start = NULL;

void addnote(){
	int nim;
	string nama;
	node* nodebaru = new node();
	cout << "masukkan nim : ";
	cin >> nim;
	cout << "masukkan nama = ";
	cin >> nama;
	nodebaru->nomhs = nim;
	nodebaru->name = nama;

	if (start == NULL || nim <= start->nomhs) {
		if (start != NULL && nim == start->nomhs) {
			cout << "nim sudah ada" << endl;
			return;
		}

		node* current = start;
		node* previous = start;

		while ((current != NULL) && (nim >= current->nomhs)) {
			if (nim == current->nomhs) {
				cout << "nim sudah ada" << endl;
				return;
			}
			previous = current;
			current = current->next;
		}
		nodebaru->next = current;
		previous->next = nodebaru;
	}

}

bool searchnode(int nim, node* current, node* previous){
	previous = start;
	current = start;
	while {
		previous = start;
		current = start;
	}
};

void{

};

