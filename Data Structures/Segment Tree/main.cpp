#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int getValue(int index, int u, int v, int l, int r, int Tree[])
{
    if (r < u || v < l) return INT_MIN;

    if (r <= v && l >= u) return Tree[index];

    int m = (l + r) / 2;

    return max(getValue(index*2, u, v, l, m, Tree), getValue(index*2 + 1, u, v, m+1, r, Tree));
}

void updateValue(int index, int l, int r, int i, int target, int A[], int Tree[])
{
    if (i < l || i > r) return;

    if (l == r)
    {
        Tree[index] = target;
        return;
    }

    int m = (l + r) / 2;
    updateValue(index*2, l, m, i, target, A, Tree);
    updateValue(index*2 + 1, m+1, r, i, target, A, Tree);

    Tree[index] = max(Tree[index*2], Tree[index*2 + 1]);
}

void buildTree(int index, int l, int r, int ST[], int S[])
{
    if (l == r) 
    {
        ST[index] = S[l];
        return;
    }

    int m = (l + r) / 2;
    buildTree(index*2, l, m, ST, S);
    buildTree(index*2 + 1, m+1, r, ST, S);

    ST[index] = max(ST[index*2], ST[index*2 + 1]);

    return;
}

int main()
{
    int A[MAX], N, Tree[4*MAX];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    buildTree(1, 1, N, Tree, A);

    for (int i = 1; i <= 4*N; i++)
        cout << Tree[i] << " ";

    updateValue(1, 1, N, 3, 15, A, Tree);

    cout << '\n';

    cout << getValue(1, 1, 5, 1, N, Tree) << endl;
    
    return 0;
}