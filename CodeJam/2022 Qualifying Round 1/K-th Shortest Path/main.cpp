#include <bits/stdc++.h>

using namespace std;

#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
// typedef long long ll;
#define ll long long

int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
ll mult[10][10][10][10];

void init()
{
    memset(mult, 0, sizeof(mult));

    FOR(a,0,10) {
        FOR(b,0,10) {
            FOR(c,0,10) {
                FOR(d,0,10)
                {
                    int total = a + b + c + d;
                    if (total == 0 || total == a || total == b || total == c || total == d) mult[a][b][c][d] = 1;
                    else {
                        if (a > 0) mult[a][b][c][d] += mult[a-1][b][c][d];
                        if (b > 0) mult[a][b][c][d] += mult[a][b-1][c][d];
                        if (c > 0) mult[a][b][c][d] += mult[a][b][c-1][d];
                        if (d > 0) mult[a][b][c][d] += mult[a][b][c][d-1];
                    }
                }
            }
        }
    }
}

ll get_mult(int x, int y)
{
    int dig[4];
    FOR(i,0,4) {
      int dx = (x % p[i+1]) / p[i];
      int dy = (y % p[i+1]) / p[i];
      dig[3-i] = abs(dx-dy);
    }
    return mult[dig[0]][dig[1]][dig[2]][dig[3]];
}

void solve(int L, ll K, int x, int y)
{
    int tx = x, ty = y, size = 0;
    FOR(i,0,4) {
        int dx = tx % 10;
        tx /= 10;
        int dy = ty % 10;
        ty /= 10;
        size += abs(dx - dy);
    }

    int ans[size+1], count = 0;
    ans[count++] = x;

    while (x != y)
    {
        set<int> next;
        FOR(i,0,4) {
            int dx = (x%p[i+1]) / p[i];
            int dy = (y%p[i+1]) / p[i];
            int diff = dx - dy;
            int z = x;

            if (diff < 0) z += p[i];
            else if (diff > 0) z -= p[i];
            else continue;

            next.insert(z);
        }

        int next_node = -1;
        FORE(it,next) {
            ll max_nums_path = get_mult(*it, y);
            if (max_nums_path < K) {
                K -= max_nums_path;
            } else {
                next_node = *it;
                break;
            }
        }

        if(next_node == -1) {
            printf("NO\n");
            return;
        }

        x = next_node;
        ans[count++] = x;
    }

    const char* format;
    if (L == 2) format = "%02d";
    if (L == 3) format = "%03d";
    if (L == 4) format = "%04d";

    FOR(i,0,size) {
        printf(format, ans[i]);
        printf(" ");
    }

    printf(format, ans[size]);
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int T;
    scanf("%d", &T);

    while (T--)
    {
        int L, x, y;
        ll K;

        scanf("%d%lld%d%d", &L, &K, &x, &y);
        solve(L, K, x, y);
    }

    return 0;
}
