#ifndef E_COMMERCE_H
#define E_COMMERCE_H

#include <iostream>
#include <string>

using namespace std;

// Transaksi (Child)
struct Transaksi {
    int idTransaksi;
    int jumlah;
    float totalHarga;
    Transaksi* prev;
    Transaksi* next;
};

// Barang (Parent)
struct Barang {
    int idBarang;
    string namaBarang;
    float hargaBarang;
    Transaksi* child;
    Barang* next;
};

// Fungsi Barang (Parent)
Barang* buatBarang(int id, string nama, float harga);
void insertBarangDepan(Barang*& head, int id, string nama, float harga);
void insertBarangBelakang(Barang*& head, int id, string nama, float harga);
void showAllBarang(Barang* head);
void hapusBarang(Barang*& head, int idBarang);
Barang* cariBarang(Barang* head, int idBarang);
void ubahDataBarang(Barang* barang, string namaBaru, float hargaBaru);

// Fungsi Transaksi (Child)
Transaksi* buatTransaksi(int id, int jumlah, float total);
void insertTransaksi(Barang* barang, int idTransaksi, int jumlah);
void showAllBarangDenganTransaksi(Barang* head);
Transaksi* cariTransaksi(Transaksi* childHead, int idTransaksi);
void ubahDataTransaksi(Transaksi* transaksi, int jumlahBaru, float hargaBarang);


void hapusTransaksi(Barang* barang, int idTransaksi);
void hitungTotalTransaksi(Barang* head);

#endif /* E_COMMERCE_H */
