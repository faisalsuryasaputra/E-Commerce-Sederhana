#include "e_commerce.h"


int main() {
    Barang* head = nullptr; // Pointer ke linked list barang
    int pilihan; // Variabel pilihan menu

    do {
        cout << "\n=== MENU E-COMMERCE ===\n";
        cout << "1. Tambah Barang (Depan)\n";
        cout << "2. Tambah Barang (Belakang)\n";
        cout << "3. Tampilkan Semua Barang\n";
        cout << "4. Tambah Transaksi ke Barang\n";
        cout << "5. Tampilkan Barang dan Transaksinya\n";
        cout << "6. Cari Barang\n";
        cout << "7. Ubah Data Barang\n";
        cout << "8. Cari Transaksi pada Barang\n";
        cout << "9. Ubah Data Transaksi\n";
        cout << "10. Hapus Transaksi\n";
        cout << "11. Hapus Barang dan Transaksinya\n";
        cout << "12. Hitung Total Transaksi\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id; string nama; float harga;
            cout << "ID Barang: "; cin >> id;
            cout << "Nama Barang: "; cin.ignore(); getline(cin, nama);
            cout << "Harga Barang: "; cin >> harga;
            insertBarangDepan(head, id, nama, harga);
        }
        else if (pilihan == 2) {
            int id; string nama; float harga;
            cout << "ID Barang: "; cin >> id;
            cout << "Nama Barang: "; cin.ignore(); getline(cin, nama);
            cout << "Harga Barang: "; cin >> harga;
            insertBarangBelakang(head, id, nama, harga);
        }
        else if (pilihan == 3) {
            showAllBarang(head);
        }
        else if (pilihan == 4) {
            int idBarang, idTransaksi, jumlah; float totalHarga;
            cout << "ID Barang (untuk Transaksi): "; cin >> idBarang;

            Barang* barang = cariBarang(head, idBarang);
            if (barang == nullptr) {
                cout << "Barang tidak ditemukan!\n";
                continue;
            }

            cout << "ID Transaksi: "; cin >> idTransaksi;
            cout << "Jumlah: "; cin >> jumlah;
            //cout << "Total Harga: "; cin >> totalHarga;

            insertTransaksi(barang, idTransaksi, jumlah);
        }
        else if (pilihan == 5) {
            showAllBarangDenganTransaksi(head);
        }
        else if (pilihan == 6) {
            int idBarang;
            cout << "ID Barang yang dicari: "; cin >> idBarang;

            Barang* barang = cariBarang(head, idBarang);
            if (barang != nullptr) {
                cout << "Barang ditemukan!\n";
                cout << "ID: " << barang->idBarang << ", Nama: " << barang->namaBarang
                     << ", Harga: " << barang->hargaBarang << endl;
            } else {
                cout << "Barang tidak ditemukan!\n";
            }
        }
        else if (pilihan == 7) {
            int idBarang; string namaBaru; float hargaBaru;
            cout << "ID Barang yang ingin diubah: "; cin >> idBarang;

            Barang* barang = cariBarang(head, idBarang);
            if (barang == nullptr) {
                cout << "Barang tidak ditemukan!\n";
                continue;
            }

            cout << "Nama Baru: "; cin.ignore(); getline(cin, namaBaru);
            cout << "Harga Baru: "; cin >> hargaBaru;

            ubahDataBarang(barang, namaBaru, hargaBaru);
        }
        else if (pilihan == 8) {
            int idBarang, idTransaksi;
            cout << "ID Barang: "; cin >> idBarang;

            Barang* barang = cariBarang(head, idBarang);
            if (barang == nullptr) {
                cout << "Barang tidak ditemukan!\n";
                continue;
            }

            cout << "ID Transaksi: "; cin >> idTransaksi;
            Transaksi* transaksi = cariTransaksi(barang->child, idTransaksi);
            if (transaksi != nullptr) {
                cout << "Transaksi ditemukan!\n";
                cout << "ID Transaksi: " << transaksi->idTransaksi
                     << ", Jumlah: " << transaksi->jumlah
                     << ", Total Harga: " << transaksi->totalHarga << endl;
            } else {
                cout << "Transaksi tidak ditemukan!\n";
            }
        }
        else if (pilihan == 9) {
    int idBarang, idTransaksi, jumlahBaru;
    cout << "ID Barang: "; cin >> idBarang;

    Barang* barang = cariBarang(head, idBarang);
    if (barang == nullptr) {
        cout << "Barang tidak ditemukan!\n";
        continue;
    }

    cout << "ID Transaksi: "; cin >> idTransaksi;
    Transaksi* transaksi = cariTransaksi(barang->child, idTransaksi);
    if (transaksi != nullptr) {
        cout << "Jumlah Baru: "; cin >> jumlahBaru;
        ubahDataTransaksi(transaksi, jumlahBaru, barang->hargaBarang);
    } else {
        cout << "Transaksi tidak ditemukan!\n";
    }
}

        else if (pilihan == 10) {
            int idBarang, idTransaksi;
            cout << "ID Barang: "; cin >> idBarang;

            Barang* barang = cariBarang(head, idBarang);
            if (barang == nullptr) {
                cout << "Barang tidak ditemukan!\n";
                continue;
            }

            cout << "ID Transaksi yang ingin dihapus: "; cin >> idTransaksi;
            hapusTransaksi(barang, idTransaksi);
        }
        else if (pilihan == 11) {
            int idBarang;
            cout << "ID Barang yang ingin dihapus: "; cin >> idBarang;
            hapusBarang(head, idBarang);
        }
        else if (pilihan == 12) {
            hitungTotalTransaksi(head);
        }
        else if (pilihan != 0) {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    cout << "Program selesai. Terima kasih!\n";
    return 0;
}
