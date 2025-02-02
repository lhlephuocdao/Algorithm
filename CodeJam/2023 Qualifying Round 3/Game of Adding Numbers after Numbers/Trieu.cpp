#include<bits/stdc++.h>
using namespace std;
//int ne = 0, de = 0;
int A[500010], B[500010];
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
    int size;
    int repeat;
    int lazy;
    long long sum;
};

Node pool[100000];
int use = 0;

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}


void lazyAdd(Node* node, int value)
{
    node-> sum += value * node->size;
    node -> key += value;
    if(node->left) node->left->lazy += value;
    if(node->right) node->right->lazy += value;
}

Node* newNode(long long key, int size)
{
    //ne++;
	Node &node = pool[use];
	node.key = key;
	node.left = NULL;
	node.right = NULL;
	node.height = 1;
    node.size = size;
    node.repeat = size;
    node.sum = key * size;
    node.lazy = 0;
	return &pool[use++];
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

    long long s1 = x -> sum, s2 = y -> sum, s3 = 0;
    int m1 = x -> size, m2 = y->size, m3= 0;

    if(T2) {
        s3 = T2 -> sum;
        m3 = T2 -> size;
    }

    if(y->lazy) {
        lazyAdd(y,y->lazy);
        y->lazy = 0;
    }
    if(x->lazy) {
        lazyAdd(x,x->lazy);
        x->lazy = 0;
    }
    
	x->right = y;
	y->left = T2;
    x-> sum = s2;
    y -> sum = s2 - s1 + s3;
    x-> size = m2;
    y -> size = m2 - m1 + m3;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

Node *leftRotate(Node *x)
{
    
	Node *y = x->right;
	Node *T2 = y->left;
    long long s1 = x -> sum, s2 = y->sum, s3= 0;
    int m1 = x -> size, m2 = y->size, m3= 0;
    if(T2) {
        s3 = T2->sum ;
        m3 = T2->size;
    }

    if(x->lazy) {
        lazyAdd(x,x->lazy);
        x->lazy = 0;
    }
    if(y->lazy) {
        lazyAdd(y,y->lazy);
        y->lazy = 0;
    }
	y->left = x;
	x->right = T2;
    y->sum = s1;
    x-> sum = s1 - s2 + s3;
    y->size = m1;
    x-> size = m1 - m2 + m3;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

long long getSmallest(Node *node, int size){
   if(size == 0) return 0;
    long long res = 0;
    if(node->left) {
        Node *l = node->left;
        if( size >= l->size) {
            if(l->lazy) {
                lazyAdd(node,l->lazy);
                l->lazy = 0;
            }
            res += l -> sum;
            size -= l->size;
        }
        else {
            return getSmallest(l, size);
        }  
    }
    if(size > 0) {
        if(size >=  node->repeat) {
            res += node ->repeat * node -> key;
            size -= node->repeat;
        }
        else {
            return res + size * node->key;
        }
    }
    if(size && node->right){
        if(size == node->right->size)
            return res + node->right->sum;
        else
            return res + getSmallest(node->right,size);
    }
    return res;
}

long long getLargest(Node *node, int size){
    if(size == 0) return 0;
    long long res = 0;
    if(node->right) {
        Node *r = node->right;
        if( size >= r->size) {

            if(r->lazy) {
                lazyAdd(node,r->lazy);
                r->lazy = 0;
            }
            res += r -> sum;
            size -= r->size;
        }
        else {
            return getLargest(r, size);
        }  
    }
    if(size > 0) {
        if(node->lazy) {
            lazyAdd(node,node->lazy);
            node->lazy = 0;
        }
        if(size >=  node->repeat) {
            res += node ->repeat * node -> key;
            size -= node->repeat;
        }
        else
            return res + size * node->key;
    }
    if(size && node->left){
        if(size == node->left->size)
            return res + node->left->sum;
        else
            return res + getLargest(node->left, size);
    }
    return res;
}

Node* insert(Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(key,1));
    if(node->lazy) {
        lazyAdd(node,node->lazy);
        node->lazy = 0;
    }
    node->sum += key;
    node->size += 1;
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else {
        node -> repeat += 1;
		return node;
    }

	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void clear(Node *root) {
    if(root->left) clear(root->left);
    if(root->right) clear(root->right);
    delete root;
}

void preOrder(Node *root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		cout << root-> key << " " << root -> repeat << " " << root -> size << " " << root-> sum << '\n';
        preOrder(root->right);
	}
}

Node* sortedArrayToBST(int *a, int *b, int start, int end)
{
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = newNode(a[mid], b[mid]);

    if(start <= ( mid - 1)) {
        root->left = sortedArrayToBST(a, b, start, mid - 1);
        root->size += root->left->size;
        root->sum += root->left->sum;
    }
    if((mid + 1) <= end){
        root->right = sortedArrayToBST(a, b, mid + 1, end);
        root->size += root->right->size;
        root->sum +=root->right->sum;
    }
 
    root->height = 1 + max(height(root->left),height(root->right));

    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        use = 0;
        Node *root = nullptr;
        int N, M, Q, W, v, n = 0;
        cin >> N >> M;
        cin >> A[0]; B[0] = 1;
        for(int i = 1; i < N;  ++i) {
            cin >> v;
            if(v == A[n])
                ++B[n];
            else {
                n++;
                B[n] = 1;
                A[n] = v;
            }
        }
        root = sortedArrayToBST(A,B,0,n);

        for(int i = 0; i < M; i++)
        {
            cin >> Q >> W;
            if(Q == 1) {
                root = insert(root, W);
            }
            else if(Q == 2) {
                lazyAdd(root,W);
            }
            else if(Q == 4) {
                if(W >= root ->size)
                    cout << root->sum << ' ';
                else
                    cout << getSmallest(root, W) << ' ';
            }
            else {
                if(W >= root ->size)
                    cout << root -> sum << ' ';
                else
                    cout << getLargest(root, W) << ' ';
            }
        }
        cout << '\n';
    }
	
	return 0;
}