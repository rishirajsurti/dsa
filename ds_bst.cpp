#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

typedef struct Node_{
	int key;
	struct Node_ *l, *r, *p;
} Node;

class BinaryTree{

public:
	Node *first;
	BinaryTree(){
	first = (Node *)malloc(sizeof(Node));
	first->p = NULL;

	}
	void addKey(int data);
	void addLeftChild();
	void moveLeft();
	void moveRight();
	void moveUp();
	void addRightChild();
	void addLeftKey(int data);
	void addRightKey(int data);
	Node* returnCurrent();
//	void display(Node *current);
	void InorderTraversal(Node *current);
};

void BinaryTree::addKey(int data){
	first->key = data;
}

void BinaryTree::addLeftChild(){
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->p = first;

	temp->l = NULL;
	temp->r = NULL;
	first->l = temp;
}

void BinaryTree::addRightChild(){
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->p = first;
	temp->l = NULL;
	temp->r = NULL;
	first->r = temp;
}

void BinaryTree::moveLeft(){
	first = first->l;
}
void BinaryTree::moveRight(){
	first = first->r;
}
void BinaryTree::moveUp(){
	first = first->p;
}
void BinaryTree::addLeftKey(int data){
	first->l->key = data;
}

void BinaryTree::addRightKey(int data){
	first->r->key = data;
}

Node* BinaryTree::returnCurrent(){
	return first;
}

void BinaryTree::InorderTraversal(Node *current){

	if(current->l != NULL)
		InorderTraversal(current->l);
	cout<<current->key<<endl;
	if(current->r != NULL)
		InorderTraversal(current->l);
}

int main(){
	BinaryTree T;
	Node *root;
	root = T.returnCurrent();
	T.addKey(1);
	T.addLeftChild();
	T.addLeftKey(2);
	T.addRightChild();
	T.addRightKey(3);
	
	T.moveLeft();
	T.addLeftChild();
	T.addLeftKey(4);
	T.addRightChild();
	T.addRightKey(5);

	T.moveUp();

	T.moveRight();
	T.addLeftChild();
	T.addLeftKey(6);
	T.addRightChild();
	T.addRightKey(7);

	cout<<root->key<<endl;
	T.InorderTraversal(root);
}