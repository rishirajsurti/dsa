#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Node_{
	int x;
	Node_ *next;
} Node;


Node* CreateLinkedList(){
	// Linked list with 4 nodes
	Node *n1, *n2, *n3, *n4;
	n1 = new Node;	n2 = new Node;	n3 = new Node; n4 = new Node;
	n1->x = 1; n1->next = n2; 
	n2->x = 2; n2->next = n3;
	n3->x = 3; n3->next = n4;
	n4->x = 4; n4->next = NULL;

	return n1;
}

void PrintLinkedList(Node *lhead, int n){ //n length of linked list

	Node *temp;	//temp = new Node;
	temp = lhead;
	for(int i=1; i<=4; i++){	
		printf("%d\n",temp->x );
		temp = temp->next;
	}
}

Node* ReverseLinkedList(Node *head, int n){
	Node *temp1;
	int temp2; //optional, data can be exchanged without defining another temporary variable;

	for(int i = 1; i <= n; i++){
		temp1 = head; //here head of linked list;
		for(int j = 1; j <= (n-i); j++){
			temp2 = temp1->x;
			temp1->x = temp1->next->x;
			temp1->next->x = temp2;
			temp1 = temp1->next;
		}
	}
	return head;
}

int main(){

	int n=4; //length of linked list;
	Node *head;
	head = CreateLinkedList();

	//Print
	printf("Original:\n");
	PrintLinkedList(head, n);
	
	// to reverse;
	head = ReverseLinkedList(head, n);

	//Print
	printf("\n\nReversed:\n");
	PrintLinkedList(head, n);
	return 0;
}
