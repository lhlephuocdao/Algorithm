#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e5 + 5;
int Nx, Ny, Nz, t;
string Sx, Sy, Sz;

void calc(set<vector<long long>> &sa, string &s, int n) {
 vector<long long> a(3);
 for(int i = 0; i <= n; i++)
  if(s[i] == 'R') s[i] = 0;
  else if(s[i] == 'G') s[i] = 1;
  else s[i] = 2;

 for(int i = 0; i < n; i++)
  if(s[i]  == s[i+1])
   a[s[i]]++;
 
 sa.insert(a);
 for(int i = 0; i <= n; i++)
  for(int j = 0; j < 3; j++) {
   if(s[i] != j) {
    vector<long long> m(a);
    if(i > 0) {
     if(s[i] == s[i-1]) m[s[i]]--;
     if(j == s[i-1]) m[j]++;
    }
    if(i < n) {
     if(s[i] == s[i+1]) m[s[i]]--;
     if(j == s[i+1]) m[j]++;
    }
    sa.insert(m);
   }
  }
}

ll main2() {
    int X, Y, Z;
    set<vector<long long>> sa, sb, sc;
    string sx = Sx, sy = Sy, sz = Sz;
    X = Nx, Y = Ny, Z = Nz;
    
    calc(sa, sx,X);
    calc(sb, sy,Y);
    calc(sc, sz,Z);
    long long res = 0, tmp;
    for(const vector<long long> &i: sa)
    for(const vector<long long> &j: sb)
    for(const vector<long long> &k: sc) {
        tmp = i[0]* j[1]*k[2] + i[0]*j[2]*k[1] + i[1]* j[0]*k[2] + i[1]*j[2]*k[0] + i[2]* j[1]*k[0] + i[2]*j[0]*k[1];
        if(tmp > res)
        res = tmp;
    }
    //  cout << res << endl; 
    return res;
}

void replaceOneChar(const string& s, set<vector<ll>>& result, ll cntR, ll cntG, ll cntB) {
    //tại mỗi vị trí, thay đổi kí tự, đếm lại cặp GRB bằng cách kiểm tra 2 kí tự trước và sau vị trí đang xét.
    //BBBRRBRRR
    int n = s.size();
    for(int i = 0; i < n; i++) {
        // cout << "string " << s << " pos " << i << " " << cntR << " " << cntG << " " << cntB << endl;
        ll tmpR = cntR, tmpG = cntG, tmpB = cntB;
        if (s[i] == 'G') {
            //Đổi s[i] thành R hoặc B
            tmpG--;
            if(i == 0) {
                if (s[i + 1] == 'R')
                    tmpR++;
                else if (s[i + 1] == 'B')
                    tmpB++;
            }
            else if (i == n-1) {
                if (s[i - 1] == 'R')
                    tmpR++;
                else if (s[i - 1] == 'B')
                    tmpB++;
            }
            else {
                if (s[i + 1] == 'R')
                    tmpR++;
                else if (s[i + 1] == 'B')
                    tmpB++;

                if (s[i - 1] == 'R')
                    tmpR++;
                else if (s[i - 1] == 'B')
                    tmpB++;
            }
            // cout << "Replace G " << tmpR << " " << tmpG << " " << tmpB << endl;
        }

        if (s[i] == 'R') {
            //Đổi s[i] thành G hoặc B
            tmpR--;
            if(i == 0) {
                if (s[i + 1] == 'G')
                    tmpG++;
                else if (s[i + 1] == 'B')
                    tmpB++;
            }
            else if (i == n-1) {
                if (s[i - 1] == 'G')
                    tmpG++;
                else if (s[i - 1] == 'B')
                    tmpB++;
            }
            else {
                if (s[i + 1] == 'G')
                    tmpG++;
                else if (s[i + 1] == 'B')
                    tmpB++;

                if (s[i - 1] == 'G')
                    tmpG++;
                else if (s[i - 1] == 'B')
                    tmpB++;
            }
            // cout << "Replace R " << tmpR << " " << tmpG << " " << tmpB << endl;
        }

        if (s[i] == 'B') {
            //Đổi s[i] thành G hoặc B
            tmpB--;
            if(i == 0) {
                if (s[i + 1] == 'G')
                    tmpG++;
                else if (s[i + 1] == 'R')
                    tmpR++;
            }
            else if (i == n-1) {
                if (s[i - 1] == 'G')
                    tmpG++;
                else if (s[i - 1] == 'R')
                    tmpR++;
            }
            else {
                if (s[i + 1] == 'G')
                    tmpG++;
                else if (s[i + 1] == 'R')
                    tmpR++;

                if (s[i - 1] == 'G')
                    tmpG++;
                else if (s[i - 1] == 'R')
                    tmpR++;
            }
            // cout << "Replace B " << tmpR << " " << tmpG << " " << tmpB << endl;
        }

        tmpR = tmpR < 0 ? 0 : tmpR;
        tmpG = tmpG < 0 ? 0 : tmpG;
        tmpB = tmpB < 0 ? 0 : tmpB;
        result.insert({tmpR, tmpG, tmpB});
    }
}

void countPairRGB(const string& s, set<vector<ll>>& result, ll cntR, ll cntG, ll cntB){
    for (size_t i = 0; i < s.size() - 1; i++) {
        if(i < s.size() - 2 && (s[i] == s[i+1] == s[i+2]))
            continue;
        if (s[i] == 'R' && s[i+1] == 'R'){
            cntR++;
        }
        else if (s[i] == 'G' && s[i+1] == 'G'){
            cntG++;
        }
        else if (s[i] == 'B' && s[i+1] == 'B'){
            cntB++;
        }
    }
    result.insert({cntR, cntG, cntB});
    replaceOneChar(s, result, cntR, cntG, cntB);
}

ll countCube(vector<ll> X, vector<ll> Y, vector<ll> Z){
    return X[0] * Y[1] * Z[2]
        + X[0] * Y[2] * Z[1]
        + X[1] * Y[0] * Z[2]
        + X[1] * Y[2] * Z[0]
        + X[2] * Y[0] * Z[1]
        + X[2] * Y[1] * Z[0];
}

ll main3()
{
    set<vector<ll>> setX, setY, setZ;
        // ll cntR = 0, cntG = 0, cntB = 0;
        countPairRGB(Sx, setX, 0, 0, 0);
        countPairRGB(Sy, setY, 0, 0, 0);
        countPairRGB(Sz, setZ, 0, 0, 0);
        
        ll result = 0;
        for (set<vector<ll>>::iterator itX = setX.begin(); itX != setX.end(); ++itX) {
            for (set<vector<ll>>::iterator itY = setY.begin(); itY != setY.end(); ++itY) {
                for (set<vector<ll>>::iterator itZ = setZ.begin(); itZ != setZ.end(); ++itZ) {
                    // Print_Vector(*itX);
                    // Print_Vector(*itY);
                    // Print_Vector(*itZ);
                    result = max(result, countCube(*itX, *itY, *itZ));
                }
            }
        }
        return result;
}

int generate_random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void stress_test() {
    int i = 1;
    map<int, char> m;
    m[1] = 'R';
    m[2] = 'G';
    m[3] = 'B';
    while(1) {
        Sx.clear();
        Sy.clear();
        Sz.clear();
        cout << "Iteration: " << i << "\n";
        t = generate_random_int(1, 20);
        Nx = generate_random_int(1, 10);
        Ny = generate_random_int(1, 10);
        Nz = generate_random_int(1, 10);
        Sx.resize(Nx+1);
        Sy.resize(Ny+1);
        Sz.resize(Nz+1);
        for (int j = 0; j <= Nx; j++) {
            int tmp = generate_random_int(1,3);
            Sx[j] = m[tmp];
        }
        for (int j = 0; j <= Ny; j++) {
            int tmp = generate_random_int(1,3);
            Sy[j] = m[tmp];
        }
        for (int j = 0; j <= Nz; j++) {
            int tmp = generate_random_int(1,3);
            Sz[j] = m[tmp];
        }

        ll ans1 = main3();
        ll ans2 = main2();
        if(ans1 != ans2) {
            cout << "FALSE: Nx = " << Nx << " Ny = " << Ny << " Nz = " << Nz << '\n';
            cout << "Sx: " << Sx << '\n';
            cout << "Sy: " << Sy << '\n';
            cout << "Sz: " << Sz << '\n';
            cout << "EXPECTED: " << ans2 << '\n';
            cout << "ACTUAL: " << ans1 << '\n';
            break;
        }
        cout << "PASS\n";
        ++i;
    }
}

int main() {
    srand(time(0));
    stress_test();
    return 0;
}