#include <iostream>
#include <conio.h>

//Struct
typedef struct TNode {
	int data;
	TNode *next;
};

//Pointers;
TNode* baru, * awal, * akhir, * bantu_tampil, *bantu_cari;

//Functions
void _init();
void menu();
void tanya(int*);
void alokasi();
void tambah();
void tambah_pertama();
void tambah_depan();
void tambah_tengah();
void tambah_belakang();
void tampil();
void cari();

//Main
int main() {
	bool lanjut = true;
	int pilihan = 0;
	do {
		system("CLS");
		menu();
		tanya(&pilihan);
		switch (pilihan) {
		case 1:
			alokasi();
			if (akhir == NULL) {
				tambah_pertama();
			}
			else {
				tambah();
			}
			break;
		case 2:
			cari();
			break;
		case 3:
			tampil();
			break;
		default:
			std::cout << "(Tekan y untuk keluar!)";
			if (_getche() == 'y') {
				lanjut = false;
			}
			break;
		}
		std::cout <<"\n";
		system("PAUSE");
	} while (lanjut);
}
void _init() {
	awal = NULL;
	akhir = NULL;
}

void menu() {
	std::cout << "MENU\n";
	std::cout << "1. Tambah data\n";
	std::cout << "2. Cari data\n";
	std::cout << "3. Tampil semua data\n";
	std::cout << "?? Keluar\n";
}

void tanya(int* storage) {
	std::cout << "Pilih menu : ";
	std::cin >> *storage;
}

void alokasi() {
	int data_baru;
	baru = (TNode*)malloc(sizeof(struct TNode));
	std::cout << "Masukan data : ";
	std::cin >> data_baru;
	baru->data = data_baru;
}

void tambah() {
	int ps;
	std::cout << "Pilihan penambahan : \n";
	std::cout << "1.Tambah depan\n";
	std::cout << "2.Tambah tengah\n";
	std::cout << "3.Tambah belakang\n";
	std::cout << "Pilih posisi : ";
	std::cin >> ps;
	switch (ps) {
	case 1:tambah_depan(); break;
	case 2:tambah_tengah(); break;
	case 3:tambah_belakang(); break;
	}
}
void tambah_pertama() {
	awal = baru;
	akhir = baru;
	baru->next = NULL;
	akhir->next = NULL;
	std::cout << "Data pertama berhasil ditambahkan\n";
}
void tambah_depan() {
	baru->next = awal;
	awal = baru;
	std::cout << "Tambah depan berhasil\n";
}
void tambah_tengah() {
		// Membuat pointer tengah dan depan;  
		TNode* tengah = awal;
		TNode* depan = (awal)->next;
		//Perulangan selama pointer depan dan depan->next bukan NULL.
		while (depan && depan->next) {
			// setiap iterasi akan memajukan pointer 1 kali.
			tengah = tengah->next;
			// setiap iterasi akan memajukan pointer 2 kali. 
			depan = depan->next->next;
		}
		// memasukan node baru pada posisi tengah.
		baru->next = tengah->next;
		tengah->next = baru;
		std::cout << "Tambah tengah berhasil\n";
}
void tambah_belakang() {
	baru->next = NULL;
	akhir->next = baru;
	akhir = baru;
	std::cout << "Tambah belakang berhasil\n";
}

void cari() {
	int c_data = 0;
	bool ketemu = false;
	std::cout << "Masukan data yang ingin dicari : ";
	std::cin >> c_data;
	if (awal == NULL) {
		std::cout << "Nak cari apa ? LinkedList pun masi kosong!";
	}
	else {
		bantu_cari = awal;
		do {
			if (bantu_cari->data == c_data) {
				ketemu = true;
				std::cout << "Data ditemukan\n";
				std::cout << "Lokasi : " << bantu_cari<<"\n";
			}
			else {
				bantu_cari = bantu_cari->next;
			}
		} while (!ketemu && bantu_cari != NULL);
		if (!ketemu) {
			std::cout << "Data yang dicari tidak ditemukan!";
		}
	}
}

void tampil() {
	if (awal == NULL) {
		std::cout << "Nak lihat apa ? LinkedList pun masi kosong!";
	}
	else {
		bantu_tampil = awal;
		std::cout << "Data : \n";
		do {
			std::cout<< bantu_tampil->data<<" | ";
			bantu_tampil = bantu_tampil->next;
		} while (bantu_tampil != NULL);
	}
}