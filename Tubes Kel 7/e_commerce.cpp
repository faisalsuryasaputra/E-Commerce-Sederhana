#include "e_commerce.h"

// Fungsi untuk membuat Barang baru
Barang* buatBarang(int id, string nama, float harga) {
    Barang* newBarang = new Barang;
    newBarang->idBarang = id;
    newBarang->namaBarang = nama;
    newBarang->hargaBarang = harga;
    newBarang->child = nullptr;
    newBarang->next = nullptr;
    return newBarang;
}

// Insert Barang di Depan
void insertBarangDepan(Barang*& head, int id, string nama, float harga) {
    Barang* newBarang = buatBarang(id, nama, harga);
    newBarang->next = head;
    head = newBarang;
}

// Insert Barang di Belakang
void insertBarangBelakang(Barang*& head, int id, string nama, float harga) {
    Barang* newBarang = buatBarang(id, nama, harga);
    if (head == nullptr) {
        head = newBarang;
    } else {
        Barang* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newBarang;
    }
}

// Show Semua Barang
void showAllBarang(Barang* head) {
    Barang* temp = head;
    cout << "\nDaftar Barang:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->idBarang << ", Nama: " << temp->namaBarang << ", Harga: " << temp->hargaBarang << "\n";
        temp = temp->next;
    }
}

// Hapus Barang (beserta transaksinya)
void hapusBarang(Barang*& head, int idBarang) {
    Barang* temp = head, *prev = nullptr;

    while (temp != nullptr && temp->idBarang != idBarang) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Barang tidak ditemukan.\n";
        return;
    }

    // Hapus semua transaksi
    Transaksi* t = temp->child;
    while (t != nullptr) {
        Transaksi* next = t->next;
        delete t;
        t = next;
    }

    // Hapus barang
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Barang berhasil dihapus beserta transaksinya.\n";
}

// Cari Barang
Barang* cariBarang(Barang* head, int idBarang) {
    while (head != nullptr) {
        if (head->idBarang == idBarang) return head;
        head = head->next;
    }
    return nullptr;
}

// Ubah Data Barang
void ubahDataBarang(Barang* barang, string namaBaru, float hargaBaru) {
    if (barang) {
        barang->namaBarang = namaBaru;
        barang->hargaBarang = hargaBaru;
        cout << "Data barang berhasil diubah.\n";
    }
}

// Membuat Transaksi
Transaksi* buatTransaksi(int id, int jumlah, float total) {
    Transaksi* newTrans = new Transaksi{id, jumlah, total, nullptr, nullptr};
    return newTrans;
}

// Insert Transaksi (total harga dihitung otomatis)
void insertTransaksi(Barang* barang, int idTransaksi, int jumlah) {
    if (barang == nullptr) {
        cout << "Barang tidak ditemukan, transaksi tidak bisa ditambahkan.\n";
        return;
    }

    float totalHarga = jumlah * barang->hargaBarang; // Hitung total harga otomatis
    Transaksi* newTrans = buatTransaksi(idTransaksi, jumlah, totalHarga);

    newTrans->next = barang->child;
    if (barang->child != nullptr) {
        barang->child->prev = newTrans;
    }
    barang->child = newTrans;

    cout << "Transaksi berhasil ditambahkan. Total Harga: " << totalHarga << endl;
}


// Cari Transaksi
Transaksi* cariTransaksi(Transaksi* head, int idTransaksi) {
    while (head) {
        if (head->idTransaksi == idTransaksi) return head;
        head = head->next;
    }
    return nullptr;
}

// Ubah Transaksi
void ubahDataTransaksi(Transaksi* transaksi, int jumlahBaru, float hargaBarang) {
    if (transaksi) {
        transaksi->jumlah = jumlahBaru;
        transaksi->totalHarga = jumlahBaru * hargaBarang; // Hitung ulang total harga
        cout << "Data transaksi berhasil diubah.\n";
    }
}


// Hapus Transaksi
void hapusTransaksi(Barang* barang, int idTransaksi) {
    Transaksi* temp = barang->child, *prev = nullptr;

    while (temp && temp->idTransaksi != idTransaksi) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Transaksi tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) barang->child = temp->next;
    else prev->next = temp->next;

    delete temp;
    cout << "Transaksi berhasil dihapus.\n";
}

// Show Barang beserta Transaksinya
void showAllBarangDenganTransaksi(Barang* head) {
    while (head) {
        cout << "\nID Barang: " << head->idBarang << ", Nama: " << head->namaBarang << "\n";
        Transaksi* t = head->child;
        while (t) {
            cout << "\tID Transaksi: " << t->idTransaksi << ", Jumlah: " << t->jumlah << ", Total Harga: " << t->totalHarga << "\n";
            t = t->next;
        }
        head = head->next;
    }
}

// Hitung Total Transaksi
void hitungTotalTransaksi(Barang* head) {
    while (head) {
        float total = 0;
        Transaksi* t = head->child;
        while (t) {
            total += t->totalHarga;
            t = t->next;
        }
        cout << "Total Transaksi untuk Barang " << head->namaBarang << ": " << total << endl;
        head = head->next;
    }
}
