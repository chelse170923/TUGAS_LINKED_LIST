#include <iostream>
#include <string>
using namespace std;

struct Buku { string judul; string penulis; int tahun; };

int main() { Buku buku[100]; int jumlah = 0; int pilihan;

do {
    cout << "\n=== SISTEM DATA PERPUSTAKAAN ===" << endl;
    cout << "1. Tambah Data Buku" << endl;
    cout << "2. Tampilkan Data Buku" << endl;
    cout << "3. Cari Buku" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1:
            cout << "\nMasukkan Judul Buku : ";
            getline(cin, buku[jumlah].judul);

            cout << "Masukkan Nama Penulis : ";
            getline(cin, buku[jumlah].penulis);

            cout << "Masukkan Tahun Terbit : ";
            cin >> buku[jumlah].tahun;
            cin.ignore();

            jumlah++;
            cout << "Data buku berhasil ditambahkan!" << endl;
            break;

        case 2:
            cout << "\n=== DATA BUKU ===" << endl;

            if (jumlah == 0) {
                cout << "Belum ada data buku." << endl;
            } else {
                for (int i = 0; i < jumlah; i++) {
                    cout << "\nData Buku Ke-" << i + 1 << endl;
                    cout << "Judul   : " << buku[i].judul << endl;
                    cout << "Penulis : " << buku[i].penulis << endl;
                    cout << "Tahun   : " << buku[i].tahun << endl;
                }
            }
            break;

        case 3: {
            string cari;
            bool ditemukan = false;

            cout << "\nMasukkan Judul Buku yang Dicari : ";
            getline(cin, cari);

            for (int i = 0; i < jumlah; i++) {
                if (buku[i].judul == cari) {
                    cout << "\nBuku ditemukan!" << endl;
                    cout << "Judul   : " << buku[i].judul << endl;
                    cout << "Penulis : " << buku[i].penulis << endl;
                    cout << "Tahun   : " << buku[i].tahun << endl;
                    ditemukan = true;
                }
            }

            if (!ditemukan) {
                cout << "Buku tidak ditemukan." << endl;
            }
            break;
        }

        case 4:
            cout << "\nProgram selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
    }

} while (pilihan != 4);

return 0;

}
