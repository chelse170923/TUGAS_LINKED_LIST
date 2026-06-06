#include <iostream>
using namespace std;
struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top;
};

void init(Stack &s) {
    s.top = NULL;
}

void push(Stack &s, string teks) {
    Node* baru = new Node;
    baru->data = teks;
    baru->next = s.top;
    s.top = baru;
}

string pop(Stack &s) {
    if (s.top == NULL) {
        return "";
    } else {
        Node* hapus = s.top;
        string hasil = hapus->data;

        s.top = s.top->next;
        delete hapus;

        return hasil;
    }
}

bool isEmpty(Stack s) {
    return s.top == NULL;
}

int main() {
    Stack undoStack;
    init(undoStack);

    string dokumen = "";
    string teks;
    int pilih;

    do {
        cout << "\n===== TEXT EDITOR =====" << endl;
        cout << "1. Ketik Teks" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Tampilkan Dokumen" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch(pilih) {

            case 1:
                push(undoStack, dokumen);

                cout << "Masukkan teks: ";
                getline(cin, teks);

                dokumen += teks + "\n";

                cout << "Teks berhasil ditambahkan!" << endl;
                break;

            case 2:
                if (!isEmpty(undoStack)) {
                    dokumen = pop(undoStack);

                    cout << "Undo berhasil!" << endl;
                } else {
                    cout << "Tidak ada data untuk undo!" << endl;
                }
                break;

            case 3:
                cout << "\n===== ISI DOKUMEN =====" << endl;

                if (dokumen == "") {
                    cout << "Dokumen kosong." << endl;
                } else {
                    cout << dokumen << endl;
                }
                break;

            case 4:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilih != 4);

    return 0;
}
