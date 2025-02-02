#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 7;
const int MAX = 1e9+1;

int n, V[maxN];
struct node {
    int index;
    int x;
    int y;
    int first;
    int second;
} a[maxN];

int f[maxN], s[maxN];

void add(int BIT[], int id, int val)
{
    while (id <= maxN)
    {
        BIT[id] += val;
        id += (id & (-id));
    }
}

int get(int BIT[], int id)
{
    int sum = 0;
    while (id > 0)
    {
        sum += BIT[id];
        id -= (id & (-id));
    }
    return sum;
}

int range(int BIT[], int a, int b)
{
    return get(BIT, b) - get(BIT, a-1);
}

bool operator<(const node& a, const node& b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].index = i;
        cin >> a[i].x >> a[i].y;
        V[i]= a[i].y;
    }

    sort(a+1, a+n+1);
    sort(V+1, V+n+1);

    int size = unique(V+1, V+n+1)-V-1;
    for (int i = 1; i<=n; i++)
        a[i].y = lower_bound(V+1, V+1+size, a[i].y)-V;

    for (int i = 1; i <= n; i++) {
        add(f, a[i].y, 1);
        add(s, a[i].y, 1);
    }

    for (int i = 1; i <= n; i++) {
        add(f, a[i].y, -1);
        a[i].first = get(f, a[i].y);
    }

    for (int i = n; i >= 1; i--) {
        add(s, a[i].y, -1);
        a[i].second = range(s, a[i].y, maxN);
    }

    int first[maxN], second[maxN];
    for (int i = 1; i <= n; i++) {
        first[a[i].index] = a[i].first;
        second[a[i].index] = a[i].second;
    }

    for (int i = 1; i <= n; i++)
        cout << first[i] << " ";
    cout << '\n';

    for (int i = 1; i <= n; i++)
        cout << second[i] << " ";
    cout << '\n';

    return 0;
}