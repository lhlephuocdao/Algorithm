#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
#define MODULO 1000000007
#define MAXN 50005

struct Point {
    int x, y, id;
    bool is_rect;
    bool visited;
};

bool cmp(const Point& p1, const Point& p2) {
    if (p1.x != p2.x)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

bool cmpY(const Point& p1, const Point& p2) {
    if (p1.y != p2.y)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

int N,M,Q, C[MAXN];
vector<Point> points;

int cal(int index, int start )
{
    int next = -1;
    for (int i = index+1; i < N+M; i++){
        if (points[i].is_rect && points[i].y >= points[index].y) {
            next = i;
            break;
        }
    }

    // cout << "index: " << index << '\n';
    // cout << "next: " << next << '\n';

    int add = (next != -1) ? cal(next, index+1) : 0;

    // cout << "index: " << index << '\n';
    // cout << "start: " << start << '\n';
    for (int i = index-1; i >= start; i--) {
        if (!points[i].is_rect && !points[i].visited && points[i].y <= points[index].y) {
            C[points[i].id] += add + 1;
            // cout << "points[i].id: " << points[i].id << "   C[" << points[i].id <<"]: " << C[points[i].id] << '\n';
            points[i].visited = true;
        }
    }

    points[index].visited = true;

    return 1;
}

int cal2(int index, int start )
{
    int next = -1;
    for (int i = index+1; i < N+M; i++){
        if (points[i].is_rect && points[i].x >= points[index].x) {
            next = i;
            break;
        }
    }

    // cout << "index: " << index << '\n';
    // cout << "next: " << next << '\n';

    int add = (next != -1) ? cal2(next, index+1) : 0;

    // cout << "index: " << index << '\n';
    // cout << "start: " << start << '\n';
    for (int i = index-1; i >= start; i--) {
        if (!points[i].is_rect  && points[i].x <= points[index].x) {
            C[points[i].id] += add + 1;
            // cout << "points[i].id: " << points[i].id << "   C[" << points[i].id <<"]: " << C[points[i].id] << '\n';
            points[i].visited = true;
        }
    }

    points[index].visited = true;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--) {
        points.clear();
        cin >> N >> M >> Q;

        int X[N], Y[N], W[M], H[M], L[Q], U[Q];

        FOR(i,0,N) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y, i, false, false});
            C[i] = 0;
        }

        map<int, int> m;
        m[M] = 0;
        FOR(j,0,M) {
            int w,h;
            cin >> w >> h;
            points.push_back({w, h, j, true, false});
            m[j] = 0;
        }

        sort(points.begin(), points.end(), cmp);
        int start_rect;
        FOR(i,0,N+M) {
            if(points[i].is_rect) {
                start_rect = i;
                break;
            }
        }

        int start_p;
        FOR(i,0,N+M) {
            if(!points[i].is_rect) {
                start_p = i;
                break;
            }
        }

        cal(start_rect, start_p);

        sort(points.begin(), points.end(), cmpY);

        FOR(i,0,N+M) {
            if(points[i].is_rect && !points[i].visited) {
                start_rect = i;
                break;
            }
        }

        cal2(start_rect, start_p);

        FOR(i,0,N)
            cout  << C[i] << " ";
        cout << '\n';


        for (int i = N-1; i >= 0; i--) {
            // int s_pos = lower_bound(rects.begin(), rects.end(), Rect{X[i],Y[i]}) - rects.begin();
            // for (int j = s_pos; j < M; j++)
            //     if (rects[j].h >= Y[i]) C[i]++;

            m[C[i]]++;
        }

        FOR(k,0,Q) {
            cin >> L[k] >> U[k];
        }

        int prefix[M+2];
        prefix[0] = 0;

        FOR(i,0,M+1) {
            prefix[i+1] = prefix[i] + m[i]; 
        }

        FOR(k,0,Q) {
            int ans = prefix[U[k]+1] - prefix[L[k]];
            cout << ans << " ";
        }
        cout << '\n';

    }

    return 0;
}