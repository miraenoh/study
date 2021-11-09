#include <stdio.h>
#include <stdlib.h>

#define INPUTNAME "qa.inp"
#define OUTPUTNAME "qa.out"

typedef struct tnode {
	
	int key;
	tnode* parent = NULL;
	tnode* left_child = NULL;
	tnode* right_child = NULL;
} node;

typedef struct tree {
	node* root = NULL;
} tree;

void tree_insert (tree*, node*);
node* tree_search (node*, int );
void read_input_from_file(int**, int*, int*, int*);
void output_to_file(int);
int process(tree*, node*, node*);

int main (void) {
	
	int n, a, b;												//	n, a, and b
	int *values;												//	array for given items
	read_input_from_file(&values, &n, &a, &b);					//	read the input file and set n, a, b, and values
	
	tree Tree;													//	a tree for search
	//	fill the tree by using input values
	for (int i=0; i<n; ++i) {
		
		node* tmpNode = (node*)calloc(1, sizeof(*tmpNode));		//	allocate space for new node
		tmpNode->key = values[i];
		tree_insert (&Tree, tmpNode);							//	insert new node
	}
	
	//	search node A and node B
	node* nodeA = tree_search (Tree.root, a);
	node* nodeB = tree_search (Tree.root, b);
	
	int min = process (&Tree, nodeA, nodeB);					//	find the minimum value
	
	output_to_file(min);										//	write the result on the output file

	return 0;
}

int process (tree* T, node* a, node* b) {						//	find the minimum value
	
	int min = a->key;
	
	node* x = a;												//	current node
	
	while (x != T->root) {										//	go up, find the minimum value
		x = x->parent;
		if (x->key < min)
			min = x->key;
	}
	
	while (x != b) {											//	go down , find the minimum value
		if (x->key > b->key)
			x = x->left_child;
		else
			x = x->right_child;
		if (x->key < min)
			min = x->key;
	}
	return min;
}

//	insert a node
void tree_insert (tree* T, node* z) {
	
	node* y = NULL;
	node* x = T->root;
	
	while (x != NULL) {
		
		y = x;
		
		if ((z->key) < (x->key))
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

//	search a node
node* tree_search (node* x, int k) {
	
	if (x == NULL  || k == x->key)
		return x;
	if (k < x->key)
		return tree_search(x->left_child, k);
	else
		return tree_search(x->right_child, k);
}

void read_input_from_file(int** arr, int* n, int* a, int* b) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	fscanf(fptr, "%d", n);						//	read n 
	
	*arr = (int*)calloc(*n, sizeof(*arr));
	
	for (int i=0; i<*n; ++i)
		fscanf(fptr, "%d", &(*arr)[i]);			//	read n values of array 
	fscanf(fptr, "%d%d", a, b);					//	read a and b 
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);						//	writes given number on the output file.
}
