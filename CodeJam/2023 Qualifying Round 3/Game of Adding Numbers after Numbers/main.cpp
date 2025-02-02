#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
#define COUNT 10
 
const int MAXN = 50000 + 1;
int N,M;
// map<int, int> V;
int Q[MAXN], W[MAXN];
// vector<ll> A;
long long sum_add;

struct node {
	int key;
	struct node* left;
	struct node* right;
	int height;
	int count;
};

int height(struct node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

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

void getLargestSum(struct node* root, int& k, long long& ans)
{
    if (root == NULL || k == 0)
        return;

    getLargestSum(root->right, k, ans);

    if (k >= root->count) {
        ans += (root->key + sum_add) * root->count;
        k -= root->count;
    } else {
        ans += (root->key + sum_add) * k;
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
        ans += (root->key + sum_add) * root->count;
        k -= root->count;
    } else {
        ans += (root->key + sum_add) * k;
        return;
    }

    getSmallestSum(root->right, k, ans);
}

void update(struct node* root, int value)
{
    if (root == NULL)
        return;
    root->key += value;
    update(root->right, value);
    update(root->left, value);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        // V.clear();
        // A.clear();
        struct node* root = NULL;
        sum_add = 0;

        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            root = insert(root, tmp);
        }

        for (int i = 0; i < M; i++) {
            cin >> Q[i] >> W[i];
            switch (Q[i]) {
                case 1 : 
                {
                    update(root, sum_add);
                    sum_add = 0;
                    root = insert(root, W[i]);
                    break;
                }
                case 2:
                {
                    sum_add += W[i];
                    break;
                }
                case 3:
                {
                    long long ans = 0;
                    getLargestSum(root, W[i], ans);
                    cout << ans << " ";
                    break;
                }
                case 4:
                {
                    long long ans = 0;
                    getSmallestSum(root, W[i], ans);
                    cout << ans << " ";
                    break;
                }
                default:
                    break;
            }
        }
        cout << '\n';
    }
 
    return 0;
}