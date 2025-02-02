#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi countChangeColor(const string& S) {
    int n = S.size();
    vvi M;
    vi  vcount(3, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        if (S[i] == S[i + 1]) {
            if(S[i] == 'R'){
                vcount[0]++;
            }
            else if(S[i] == 'G'){
                vcount[1]++;
            }
            else if(S[i] == 'B'){
                vcount[2]++;
            }
            
        }
    }
    
    M.push_back(vcount);
    
    // R COLOR
    bool isAdd = true;
    // tang R len 2 khong giam G, B
    for (int i = 0; i < n; ++i) {
        if((S[i] == 'G' ||  S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'R') && (i > 0 && S[i - 1] == 'R'))){
            vi temp_vcount = vcount;
            temp_vcount[0] += 2;
            M.push_back(temp_vcount);
            isAdd = false;
            break;
        }
    }
    
    // tang R len 1 khong giam G
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'G') && ((i + 1 < n && S[i + 1] == 'R' && ((i > 0 && S[i - 1] != 'G') || i <= 0)) 
            || (i > 0 && S[i - 1]  == 'R' && ((i + 1 < n && S[i + 1] != 'G') || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[0] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang R  giam G
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'G') && ((i + 1 < n && S[i + 1] == 'R' && i > 0 && S[i - 1] == 'G') 
            || (i > 0 && S[i - 1] == 'R' && i + 1 < n && S[i + 1] == 'G'))){
                vi temp_vcount = vcount;
                temp_vcount[0] += 1;
                temp_vcount[1] -= 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }
 
    // tang R len 1 khong giam B
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'R' && ((i > 0 && S[i - 1] != 'B') || i <= 0)  ) 
            || (i > 0 && S[i - 1] == 'R' && ((i + 1 < n && S[i + 1] != 'B' ) || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[0] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang R  giam B
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'R' && i > 0 && S[i - 1] == 'B')
|| (i > 0 && S[i - 1] == 'R' && i + 1 < n && S[i + 1] == 'B'))){
                vi temp_vcount = vcount;
                temp_vcount[0] += 1;
                temp_vcount[2] -= 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }

    // G COLOR
    isAdd = true;
    // tang G len 2 khong giam B, R 
    for (int i = 0; i < n; ++i) {
        if((S[i] == 'R' ||  S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'G') && (i > 0 && S[i - 1]  == 'G'))){
            vi temp_vcount = vcount;
            temp_vcount[1] += 2;
            M.push_back(temp_vcount);
            isAdd = false;
            break;
        }
    }
    
    // tang G len 1 khong giam R
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'R') && ((i + 1 < n && S[i + 1] == 'G' && ((i > 0 && S[i - 1] != 'R') || i <= 0)  ) 
            || (i > 0 && S[i - 1] == 'G' && ((i + 1 < n && S[i + 1] != 'R' ) || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[1] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang G giam R
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'R') && ((i + 1 < n && S[i + 1] == 'G' && i > 0 && S[i - 1] == 'R') 
            || (i > 0 && S[i - 1] == 'G' && i + 1 < n && S[i + 1] == 'R'))){
                vi temp_vcount = vcount;
                temp_vcount[0] -= 1;
                temp_vcount[1] += 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }
 
    // tang G len 1 khong giam B
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'G' && ((i > 0 && S[i - 1] != 'B') || i <= 0 )   ) 
            || (i > 0 && S[i - 1] == 'G' && ((i + 1 < n && S[i + 1] != 'B' ) || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[1] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang G  giam B
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'B') && ((i + 1 < n && S[i + 1] == 'G' && i > 0 && S[i - 1] == 'B') 
            || (i > 0 && S[i - 1] == 'G' && i + 1 < n && S[i + 1] == 'B'))){
                vi temp_vcount = vcount;
                temp_vcount[1] += 1;
                temp_vcount[2] -= 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }
    
    // B COLOR
    isAdd = true;
    // tang B len 2 khong giam G, R 
    for (int i = 0; i < n; ++i) {
        if((S[i] == 'R' ||  S[i] == 'G') && ((i + 1 < n && S[i + 1] == 'B') && (i > 0 && S[i - 1]  == 'B'))){
            vi temp_vcount = vcount;
            temp_vcount[2] += 2;
            M.push_back(temp_vcount);
            isAdd = false;
            break;
        }
    }
    
    // tang B len 1 khong giam R
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'R') && ((i + 1 < n && S[i + 1] == 'B' && ((i > 0 && S[i - 1] != 'R') || i <= 0)  ) 
            || (i > 0 && S[i - 1] == 'B' && ((i + 1 < n && S[i + 1] != 'R' ) || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[2] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang B giam R
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'R') && ((i + 1 < n && S[i + 1] == 'B' && i > 0 && S[i - 1] == 'R') 
            || (i > 0 && S[i - 1] == 'B' && i + 1 < n && S[i + 1] == 'R'))){
                vi temp_vcount = vcount;
                temp_vcount[0] -= 1;
                temp_vcount[2] += 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }
 
    // tang B len 1 khong giam G
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'G') && ((i + 1 < n && S[i + 1] == 'B' && ((i > 0 && S[i - 1] != 'G') || i <= 0)) 
            || (i > 0 && S[i - 1] == 'B' && ((i + 1 < n && S[i + 1] != 'G' ) || i + 1 >= n)  ))){
                vi temp_vcount = vcount;
                temp_vcount[2] += 1;
                M.push_back(temp_vcount);
                isAdd = false;
                break;
            }
    
        }       
    }

    // tang B  giam G
    if(isAdd){
         for (int i = 0; i < n; ++i) {
            // check so ghep 12 chuoi con voi 1 vi tri khac
            if((S[i] == 'G') && ((i + 1 < n && S[i + 1] == 'B'&& i > 0 && S[i - 1] == 'G') 
            || (i > 0 && S[i - 1] == 'B' && i + 1 < n && S[i + 1] == 'G'))){
                vi temp_vcount = vcount;
                temp_vcount[1] -= 1;
                temp_vcount[2] += 1;
                M.push_back(temp_vcount);
                break;
            }
        }       
    }   
    
    return M;
}

ll countColorfulCubes(
    int Nx, int Ny, int Nz,
    const string& Sx, const string& Sy, const string& Sz) {

    ll maxColorCount = 0, temp = 0;

    vvi X = countChangeColor(Sx);
    vvi Y = countChangeColor(Sy);
    vvi Z = countChangeColor(Sz);

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < Y.size(); ++j) {
            for (int k = 0; k < Z.size(); ++k) {
                temp = 1ll*X[i][0]*Y[j][1]*Z[k][2] + 1ll*X[i][0]*Y[j][2]*Z[k][1]
                    + 1ll*X[i][1]*Y[j][0]*Z[k][2] + 1ll*X[i][1]*Y[j][2]*Z[k][0]
                        + 1ll*X[i][2]*Y[j][0]*Z[k][1] + 1ll*X[i][2]*Y[j][1]*Z[k][0];
                        
                if(temp > maxColorCount) maxColorCount = temp;
            }
        } 
    }
    
    return maxColorCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int Nx, Ny, Nz;
        cin >> Nx >> Ny >> Nz;
        string Sx, Sy, Sz;
        cin >> Sx >> Sy >> Sz;

        ll maxCount = countColorfulCubes(Nx+1, Ny+1, Nz+1, Sx, Sy, Sz);

        cout << maxCount << endl;
    }

    return 0;
}