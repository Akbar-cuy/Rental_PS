#include <iostream>
#include <malloc.h>
#include <cctype>
using namespace std;

struct node {
    char info;
    node *kanan, *kiri;
};

node *awal, *akhir, *bantu, *hapus, *NB;

void buatlistbaru();
void sisipnode(char IB);
void hapusnode(char IH);
void bacamaju();
void bacamundur();
int listkosong();

int main() {
    buatlistbaru();
    int pilih;
    char data;
    while (true) {
        system("cls");
        cout << "Double Linked List" << endl;
        cout << "==================" << endl;
        cout << "1. Sisip Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Baca Maju" << endl;
        cout << "4. Baca Mundur" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: "; 
        cin >> pilih;
        
        switch (pilih) {
            case 1:
                system("cls");
                int jumlah;
                cout << "Masukan jumlah node ingin disisipkan: ";  cin >> jumlah;
                for (int i = 0; i < jumlah; i++) {
                    cout << "masukan data untuk node "<< i+1 << ": ";  cin >> data;
                    sisipnode(toupper(data));
                }
                break;
            case 2:
                system("cls");
                if (listkosong()) {
                    cout << "List kosong kocak" << endl;
                    system("pause");
                    break;
                }
                cout << "Masukan jumlah node yang ingin dihapus: "; cin >> jumlah;
                for (int i = 0; i < jumlah; i++) {
                    cout << "Masukan data yang ingin dihapus: "; cin >> data;
                    hapusnode(toupper(data));
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if (listkosong()) {
                    cout << "List kosong!" << endl;
                } else {
                    cout << "Baca dari depan:" << endl;
                    bacamaju();
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if (listkosong()) {
                    cout << "List kosong!" << endl;
                } else {
                    cout << "Baca dari belakang:" << endl;
                    bacamundur();
                }
                system("pause");
                break;
            case 5:
                return 0;
            default:
                cout << "Ga ada pilihannya kocak" << endl;
                system("pause");
                break;
        }
    }
    return 0;
}

// membuat node baruu
void buatlistbaru() {
    awal = NULL;
    akhir = NULL;
}

// cek list kosong?
int listkosong() {
    return (awal == NULL);
}

void sisipnode(char IB) {
    NB = new node;
    NB->info = IB;
    NB->kanan = NULL;
    NB->kiri = NULL;
    
    if (listkosong()) {
        awal = NB;
        akhir = NB;
    }
    else if (IB <= awal->info) { // sisip depan
        NB->kanan = awal;
        awal->kiri = NB;
        awal = NB;
    }
    else {
        bantu = awal;
        while (bantu->kanan != NULL && IB > bantu->kanan->info) {
            bantu = bantu->kanan;
        }
        NB->kanan = bantu->kanan; // sisip tengah atau belakang
        if (bantu->kanan != NULL) {
            bantu->kanan->kiri = NB;
        }
        NB->kiri = bantu;
        bantu->kanan = NB;
        if (bantu == akhir) {
            akhir = NB;
        }
    }
}

void hapusnode(char IH) {
    if (listkosong()) {
        cout << "List masih kosong" << endl;
        return;
    }
    
    if (awal->info == IH) { // hapus di awal
        hapus = awal;
        awal = hapus->kanan;
        if (awal != NULL) {
            awal->kiri = NULL;
        } else {
            akhir = NULL; // list jadi kosong
        }
        cout << "Node dengan info " << IH << " telah dihapus" << endl;
        free(hapus);
        return;
    }
    
    bantu = awal;
    while (bantu->kanan != NULL && IH != bantu->kanan->info) {
        bantu = bantu->kanan;
    }
    
    if (bantu->kanan == NULL) {
        cout << "List tidak ditemukan" << endl;
        return;
    }
    
    hapus = bantu->kanan;
    if (hapus == akhir) { // hapus akhir
        akhir = bantu;
        akhir->kanan = NULL;
    } else { // hapus tengah
        bantu->kanan = hapus->kanan;
        hapus->kanan->kiri = bantu;
    }
    cout << "Node dengan info " << IH << " telah dihapus" << endl;
    free(hapus);
}

void bacamaju() {
    bantu = awal;
    while (bantu != NULL) {
        cout << bantu->info;
        if (bantu->kanan != NULL) {
            cout << " ";
        }
        bantu = bantu->kanan;
    }
    cout << endl;
}

void bacamundur() {
    bantu = akhir;
    while (bantu != NULL) {
        cout << bantu->info;
        if (bantu->kiri != NULL) {
            cout << " ";
        }
        bantu = bantu->kiri;
    }
    cout << endl;
}