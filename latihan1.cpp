#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertTail(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void tampilJumlahData() {
    Node* bantu = head;
    int no = 1, jumlah = 0;

    while (bantu != NULL) {
        cout << "Data ke " << no << ": " << bantu->data << endl;
        bantu = bantu->next;
        no++;
        jumlah++;
    }

    cout << "Jumlah data: " << jumlah << endl;
}

int main() {
    int n, nilai;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> nilai;
        insertTail(nilai);
    }

    tampilJumlahData();

    return 0;
}
