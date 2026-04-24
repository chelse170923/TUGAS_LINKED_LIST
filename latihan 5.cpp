#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insertTail(int nilai){
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;

    if(head == NULL){
        head = baru;
    }else{
        Node* bantu = head;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void tampil(){
    Node* bantu = head;

    while(bantu != NULL){
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }

    cout << "NULL";
}

int main(){
    int n, nilai, tambah;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for(int i=1; i<=n; i++){
        cout << "Masukkan data ke " << i << ": ";
        cin >> nilai;
        insertTail(nilai);
    }

    cout << "Masukkan data yang ditambahkan di akhir: ";
    cin >> tambah;

    insertTail(tambah);

    cout << "Data setelah ditambah di akhir:\n";
    tampil();
}
