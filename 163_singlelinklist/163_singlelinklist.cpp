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
	while (current != NULL && nim >= current->nomhs){
		previous = start;
		current = start;
	}
	if (current == NULL) {
		return false;
	}
	else if (current->nomhs == nim) {
		return true;
	}
	else {
		return false;
	}
};

bool deleteNode(int nim) {
	node* current = start;
	node* previous = start;
	if (searchnode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == start)

		start = current->next;
	return true;
}

bool listEmpty() {
	if (start == NULL)
		return true;
	else
		return false;
}

void traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		node* currentnode = start;
		while (currentnode != NULL) {
			cout << "NIM : " << currentnode->nomhs << "', Nama : " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void searchadata() {

};

int main() {


}