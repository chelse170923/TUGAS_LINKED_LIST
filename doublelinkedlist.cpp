#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

int main(){
	Node *node1 = NULL;
	Node *node2 = NULL;
	Node *node3 = NULL;
	
	node1 = new Node;
	node2 = new Node;
	node3 = new Node;
	
	node1->data = 10;
	node1->next = node2;
	node1->prev = node3;
	
	node2->data = 20;
	node2->next = node3;
	node2->prev = node1;
	
	node3->data = 30;
	node3->next = node1;
	node3->prev = node2;
	
	//traversal forward
	Node *nodeSekarang = node1;
	int i = 1;
	
	cout << "Traversal Forward" << endl;
	while(nodeSekarang != NULL){
		cout << "Data ke " << i++ << ": " << nodeSekarang->data << endl;
		nodeSekarang = nodeSekarang->next;
		cout << endl;
		if(nodeSekarang == node1)
		break;
	}
	//traversal backward
	cout << "Traversal backward" << endl;
	nodeSekarang = node3;
	i = 1;
	
	while(nodeSekarang != NULL){
		cout << "Data ke " << i++ << ": " << nodeSekarang->data << endl;
		nodeSekarang = nodeSekarang->prev;
		cout << endl;
		if(nodeSekarang == node3)
		break;
	}
	
	return 0;
}
