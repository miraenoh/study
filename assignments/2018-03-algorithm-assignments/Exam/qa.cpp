#include <stdio.h>
#include <stdlib.h>

#define INPUTNAME "qa.inp"
#define OUTPUTNAME "qa.out"

typedef struct tnode {									//	struct type for a node
	
	int key;
	tnode* parent = NULL;
	tnode* left_child = NULL;
	tnode* right_child = NULL;
} node;

typedef struct tree {									//	struce type for a tree
	node* root = NULL;
} tree;

void tree_insert (tree*, node*);
node* tree_search (node*, int );

void read_input_from_file(int**, int*, int*, int*);
void output_to_file(int);
int process(tree*, node*, node*);

int main (void) {
	
	int n, a, b;												//	integer values for given n, a, and b
	int *values;												//	array for given items
	read_input_from_file(&values, &n, &a, &b);					//	read the input file and set n, a, b, and values
	
	//	initialize tree and insert nodes in it
	tree Tree;													//	initialize a tree
	for (int i=0; i<n; ++i) {
		
		node* tmpNode = (node*)calloc(1, sizeof(*tmpNode));		//	allocate space for new node
		tmpNode->key = values[i];
		
		tree_insert (&Tree, tmpNode);							//	insert new node in the tree
	}
	
	//	search node A and node B
	node* nodA = tree_search (Tree.root, a);
	node* nodB = tree_search (Tree.root, b);
	
	int max = process (&Tree, nodA, nodB);						//	find the maximum value that lies in the path from node having A and node having B
	
	output_to_file(max);										//	write the result on the output file
	
	/*
	//	check
	printf("n = %d\n", n);
	for (int i=0; i<n; ++i)
		printf("%d ", values[i]);
	printf("\na = %d, b = %d\n", a, b);
	printf("root = %d\n", Tree.root->key);
	printf("right child = %d\n", Tree.root->right_child->key);
	//printf("nodeA = %d, nodeB = %d\n", nodA->key, nodB->key);
	printf("maximum value = %d\n", max);
	*/
	return 0;
}

int process (tree* T, node* a, node* b) {	//	finding max maximum value that lies in the path from A and B
	
	int max = a->key;						//	variable for maximum integer and set it as a
	node* x = a;							//	node for moving
	
	//	go up and change the max value if the key of x is bigger
	while (x != T->root) {
		x = x->parent;
		if (x->key > max)
			max = x->key;
	}
	
	//	go down and change the max value if the key of x is bigger
	while (x != b) {
		if (x->key > b->key)
			x = x->left_child;
		else
			x = x->right_child;
			
		if (x->key > max)
			max = x->key;
	}
	
	return max;
}

//	insert node z in tree T
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

//	search a node which has key value k
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
	
	fscanf(fptr, "%d", n);						//	get n from the input file
	
	*arr = (int*)calloc(*n, sizeof(*arr));
	for (int i=0; i<*n; ++i)
		fscanf(fptr, "%d", &(*arr)[i]);			//	get n values of array from the input file
	
	fscanf(fptr, "%d%d", a, b);					//	get a and b from the input file
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);						//	writes given number on the output file.
}
