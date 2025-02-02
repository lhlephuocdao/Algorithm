#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 7;

string s;
int m;

struct Node {
    int length;
    int open;
    int close;

    Node() : length(0), open(0), close(0) {}
    Node(int len, int o, int c) : length(len), open(o), close(c) {}

    Node operator+(Node const& obj)
    {
        Node node;

        int tmp = min(open, obj.close);
        node.length = length + obj.length + tmp*2;
        node.open = open + obj.open - tmp;
        node.close = close + obj.close - tmp;

        return node;
    }
};

Node st[4*maxN];

void build(int id, int l, int r)
{
    if (l == r) {
        if (s[l-1] == '(') st[id] = Node(0,1,0);
        else st[id] = Node(0,0,1);
        return;
    }

    int mid = l + r >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid+1, r);

    st[id] = st[2*id] + st[2*id+1];
}

Node get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return Node(0,0,0);
    if (l>=u && r<=v) return st[id];

    int mid = l + r >> 1;
    Node node1 = get(2*id, l, mid, u, v);
    Node node2 = get(2*id + 1, mid+1, r, u, v);

    return node1 + node2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> m;
    int n = s.length();
    build(1, 1, n);

    while (m--)
    {
        int l,r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).length << '\n';
    }

    return 0;
}