// C++ program of AVL tree that
// handles duplicates
#include <bits/stdc++.h>
using namespace std;
#define COUNT 10
// An AVL tree node
struct node {
	int key;
	struct node* left;
	struct node* right;
	int height;
	int count;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct node* newNode(int key)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	node->count = 1;
	return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node* rightRotate(struct node* y)
{
	struct node* x = y->left;
	struct node* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node* leftRotate(struct node* x)
{
	struct node* y = x->right;
	struct node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return (newNode(key));

	// If key already exists in BST, increment count and return
	if (key == node->key) {
		(node->count)++;
		return node;
	}

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* 2. Update height of this ancestor node */
	node->height = max(height(node->left), height(node->right)) + 1;

	/* 3. Get the balance factor of this ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// If key is present more than once, simply decrement
		// count and return
		if (root->count > 1) {
			(root->count)--;
			return NULL;
		}
		// Else, delete the node

		// node with only one child or no child
		if ((root->left == NULL) || (root->right == NULL)) {
			struct node* temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else // One child case
				*root = *temp; // Copy the contents of the non-empty child

			free(temp);
		}
		else {
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			struct node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node and update the count
			root->key = temp->key;
			root->count = temp->count;
			temp->count = 1;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
		return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = max(height(root->left), height(root->right)) + 1;

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
	// this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void getLargestSum(struct node* root, int& k, long long& ans)
{
    if (root == NULL || k == 0)
        return;

    getLargestSum(root->right, k, ans);

    if (k >= root->count) {
        ans += root->key * root->count;
        k -= root->count;
    } else {
        ans += root->key * k;
        return;
    }

    getLargestSum(root->left, k, ans);
}

void getSmallestSum(struct node* root, int& k, long long& ans)
{
    if (root == NULL || k == 0)
        return;

    getSmallestSum(root->left, k, ans);

    if (k >= root->count) {
        ans += root->key * root->count;
        k -= root->count;
    } else {
        ans += root->key * k;
        return;
    }

    getSmallestSum(root->right, k, ans);
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node* root)
{
	if (root != NULL) {
		cout << root->key << "("<<root->count << ")"<< " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void print2DUtil(node* root, int space){
	if (root == NULL)
		return;
	space += COUNT;

	print2DUtil(root->right, space);
	cout << endl;

	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->key << " (" << root->count << ") " << "\n";

	print2DUtil(root->left, space);
}

void print2D(node* root){
	print2DUtil(root, 0);
}

/* Driver program to test above function*/
int main()
{
	struct node* root = NULL;

	/* Constructing tree given in the above figure */
    /* 1, 7, 8, 9, 11, 12, 13, 15 */
	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 2);
	root = insert(root, 10);
	root = insert(root, 6);
	// root = insert(root, 12);
	// root = insert(root, 13);
	// root = insert(root, 15);
	// root = insert(root, 10);
	// root = insert(root, 11);
	// root = insert(root, 12);
	// root = insert(root, 13);
	// root = insert(root, 15);

	cout <<"Pre order traversal of the constructed AVL tree is \n";
    print2D(root);

	// deleteNode(root, 12);
    long long ans = 0;
    int k = 3, k1 = 3;
    getLargestSum(root, k, ans);
    cout << "sum of " << k1 << " largest elements: " << ans << '\n';

    int kk = 3, k2 = 3;
    long long mans = 0;
    getSmallestSum(root, kk, mans);
    cout << "sum of " << k2 << " smallest elements: " << mans << '\n';

	root = insert(root, 3);
	root = insert(root, 7);

    long long ans3 = 0;
    int k3 = 3, k13 = 3;
    getLargestSum(root, k3, ans3);
    cout << "sum of " << k13 << " largest elements: " << ans3 << '\n';

    int kk4 = 3, k24 = 3;
    long long mans4 = 0;
    getSmallestSum(root, kk4, mans4);
    cout << "sum of " << k24 << " smallest elements: " << mans4 << '\n';

    print2D(root);

    cout << "After insert 1\n";
	root = insert(root, 1);
    print2D(root);

	// cout <<"\nPre order traversal after deletion of 12 \n";
    // print2D(root);
	
	return 0;
}

// this code is contributed by shivanisinghss2110
