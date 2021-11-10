//	Implementation of Binary Search Tree

#include <stdio.h>

//	typedef
typedef struct tnode {
	
	int key;
	int data;
	tnode* parent;
	tnode* left_child;
	tnode* right_child;
} node;
typedef node* node_ptr;

typedef struct tree {
	
	node_ptr root;
} tree;
typedef tree* tree_ptr;

//	functions

//	tree traversal
void preorder (node_ptr ptr) {
	
	if (ptr) {	//	if there is a root
		
		printf("%d", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}
void inorder (node_ptr ptr) {
	
	if (ptr) {	//	if there is a root
		
		inorder(ptr->left_child);
		printf("%d", ptr->data);
		inorder(ptr->right_child);
	}
}
void postorder (node_ptr ptr) {
	
	if (ptr) {
		
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d", ptr->data);
	}
}

//	searching
node_ptr tree_search (node_ptr x, int k) {
	
	if (x == NULL || k == x->key)
		return x;
		
	if (k < x->key)
		return tree_search(x->left_child, k);
	else
		return tree_search(x->right_child, k);
}

//	min & max
node_ptr tree_minimum (node_ptr x) {
	
	while (x->left_child != NULL)
		x = x->left_child;
	
	return x;
}
node_ptr tree_maximum (node_ptr x) {
	
	while (x->right_child != NULL)
		x = x->right_child;
	
	return x;
}

//	successor
node_ptr tree_successor (node_ptr x) {
	
	if (x->right_child != NULL)
		return tree_minimum(x->right_child);
	
	node_ptr y = x->parent;
	while (y != NULL && x == y->right_child) {
		
		x = y;
		y = y->parent;
	}
	
	return y;
}

//	insertion
void tree_insert (tree_ptr T, node_ptr z) {
	
	node_ptr y = NULL;
	node_ptr x = T->root;
	
	while (x != NULL) {
		
		y = x;
		
		if (z->key < x->key)
			x = x->left_child;
		else
			x = x->right_child;
	}
	
	z->parent = y;
	
	if (y == NULL)
		T->root = z;
	else if (z->key < y->key)
		y->left_child = z;
	else
		y->right_child = z;
}

//	deleting
node_ptr tree_delete (tree_ptr T, node_ptr z) {
	
	node_ptr y = NULL;
	if (z->left_child == NULL || z->right_child == NULL)
		y = z;
	else
		y = tree_successor(z);
	
	node_ptr x = NULL;
	if (y->left_child != NULL)
		x = y->left_child;
	else
		x = y->right_child;
	
	//	Splice out y (x�� y�� ��ü, x�� NULL�̸� �׳� y�� �����ϴ°�) 
	if (x != NULL)
		x->parent = y->parent;
	if (y->parent == NULL)
		T->root = x;
	else if (y == y->parent->left_child)
		y->parent->left_child = x;
	else
		y->parent->right_child = x;
	
	//	z�� child�� 2���� ��� successor�� key�� data�� z�� ���� 
	if (y != z)
		z->key = y->key;
		//	copy y's satellite data into z
	
	return y;	//	��Ȱ�� �ϱ� ���� y ��ȯ 
}

int main(void) {
	
	return 0;
}
