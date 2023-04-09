#pragma once
class AVL {

struct Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
}; 

 friend struct Node;

Node* root;
int height(Node *N);
int max(int a, int b);
Node* newNode(int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node* insert(Node* node, int key);
void preOrder(Node *root);

public:

typedef Node Node;
Node* insertar(int x);
void mostrar();
Node* getRoot() const;
AVL();
AVL(Node* node);
}; 

