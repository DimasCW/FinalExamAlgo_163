#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama;
    int jumlah;
    string tipe;
    Node* next;

    Node(string nama, int jumlah, string tipe) {
        this->nama = nama;
        this->jumlah = jumlah;
        this->tipe = tipe;
        this->next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk: ";
        getline(cin, nama);
        cout << "Jumlah Produk: ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk: ";
        getline(cin, tipe);

        //isi disini
        Node* newNode = new Node(nama, jumlah, tipe);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;

            //isi disini
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;

            //isi disini
            while (current != NULL) {
                cout << "Nama: " << current->nama << endl;
                cout << "Jumlah: " << current->jumlah << endl;
                cout << "Tipe: " << current->tipe << endl;
                cout << "==========================" << endl;
                current = current->next;
            }
        }
    }

    void cariProdukByNama() {//linear search
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 0;
            bool found = false;
            while (current != NULL) {
                posisi++;

                //isi disini
                if (current->nama == targetNama) {
                    found = true;
                    cout << "Nama: " << current->nama << endl;
                    cout << "Jumlah: " << current->jumlah << endl;
                    cout << "Tipe: " << current->tipe << endl;
                    cout << "Posisi: " << posisi << endl;
                    cout << "==========================" << endl;
                }
                current = current->next;
            }

            if (!found) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algorithmaSortByJumlahProduk() {//bubble short
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current;
        Node* last = NULL;

        current = head;

        //isi disini
        bool swap;
        do {
            swap = false;
            current = head;
            while (current->next != last) {
                if (current->jumlah > current->next->jumlah) {
                    swapNodes(current, current->next);
                    swap = true;
                }
                current = current->next;
            }
            last = current;
        } while (swap);
    }

    void swapNodes(Node* node1, Node* node2) {
        string tempNama = node1->nama;
        int tempJumlah = node1->jumlah;
        string tempTipe = node1->tipe;

        node1->nama = node2->nama;
        node1->jumlah = node2->jumlah;
        node1->tipe = node2->tipe;

        node2->nama = tempNama;
        node2->jumlah = tempJumlah;
        node2->tipe = tempTipe;
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;
    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algorithmaSortByJumlahProduk();
            cout << "Produk berhasil diurutkan berdasarkan jumlah." << endl;
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}

//2. bubblesort dan linear search
//3. font dan rear pindah kedepan jika terbaca kosong dan tambahkan data baru dibelakang
//4. misalnya saat ingin membalikkan data
//5.a.5 level
//5.b. inorder dimulai sampai mentok kiri kemudian naik cek bagian kanan