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

void searchData() {
	if (listEmpty()) {
		cout << "LIst Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukkan NIM : ";
		cin >> nim;
		node* currentnode = start;
		while (currentnode != NULL) {
			if (currentnode->nomhs == nim) {
				cout << "NIM : " << currentnode->nomhs << ", Nama : " << currentnode->name << endl;
				return;
			}
			currentnode = currentnode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}

}

int main() {
	int pilihan;
	do
	{
		try
		{
			cout << "1. Tambah Data" << endl;
			cout << "2. Hapus Data" << endl;
			cout << "3. Tampilkan Data" << endl;
			cout << "4. Cari Data" << endl;
			cout << "5. Keluar" << endl;
			cout << "Pilihan : ";
			cin >> pilihan;
			switch (pilihan)
			{
			case 1:
				addnote();
				cout << "Data Berhasil Ditambahkan" << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				if (listEmpty())
				{
					cout << "List Kosong" << endl;
					system("pause");
					system("cls");
					break;
				}
				int nim;

				cout << "Masukkan NIM : ";
				cin >> nim;
				if (deleteNode(nim)) {
					cout << "nim : " << nim << " berhasil dihapus" << endl;
					system("pause");
					system("cls");
				}
				else
					cout << "Data tidak ditemukan" << endl;
				break;
			case 3:
				traverse();
				break;
			case 4:
				searchData();
				break;
			case 5:
				break;
			default:
				cout << "Pilihan tidak ada" << endl;
				break;
			}
		}
		catch (exception e)
		{
			cout << "Terjadi Kesalahan" << endl;
		}
	} while (pilihan != 5);
}