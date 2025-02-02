#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define int long long

struct Point {
    int x, y;
};

int check(Point A, Point B, Point C, Point D) {
    int ABx = B.x - A.x;
    int ABy = B.y - A.y;
    int CDx = D.x - C.x;
    int CDy = D.y - C.y;
    return (ABx * CDx + ABy * CDy);
}

double distance(Point A, Point B) {
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int X,Y,K;
        cin >> X >> Y >> K;
        if (K <= X && K <= Y) {
            cout << 0 << " " << 0 << " " << K << " " << 0 << '\n';
            cout << 0 << " " << 0 << " " << 0 << " " << K << '\n';
        } else {
            if (X > Y) X = Y;
            if (Y > X) Y = X;

            cout << 0 << " " << 0 << " " << X << " " << Y << '\n';
            cout << 0 << " " << Y << " " << X << " " << 0 << '\n';
        }
    }

    return 0;
}