#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;
 
  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
 
  inline void tie(int) {}
 
  inline explicit operator bool() {
    return cur != -1;
  }
 
  inline static bool is_blank(char c) {
    return c <= ' ';
  }
 
  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
 
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
 
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
 
  template <typename T>
  inline FastInput& read_integer(T& n) {
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }
 
  #if !defined(_WIN32) | defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;
#define cin fast_input
static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;
 
  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }
 
  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }
 
  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }
 
  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
 
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
 
  template <typename T>
  inline char* integer_to_string(T n) {
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }
 
  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.3f", n);
    return tmp;
  }
 
  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;
#define cout fast_output
#define ll long long

const int MAX = 65007;
const int mod = 1e9 + 7;

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Each element is its own parent initially
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    int find_size(int x) {
        int rootX = find(x);
        return size[rootX];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] >= size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }
};

int NA, MA, NB, MB;
int SA[MAX], SB[MAX];
bool markA[MAX], markB[MAX];
vector<vector<int>> TA, TB;

void solve()
{
    cin >> NA >> MA;
    DSU dsu_a(NA);
    memset(SA, -1, sizeof(SA));
    memset(markA, false, sizeof(markA));
    for (int i = 0; i < MA; ++i) {
        cin >> SA[i];
        --SA[i];
        markA[SA[i]] = true;
    }

    TA.clear(); TA.resize(NA);
    for (int i = 0; i < NA-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        TA[u].push_back(v);
        TA[v].push_back(u);
        if (markA[u] == false && markA[v] == false) {
            dsu_a.union_sets(u, v);
        }
    }

    cin >> NB >> MB;
    DSU dsu_b(NB);
    memset(SB, -1, sizeof(SB));
    memset(markB, false, sizeof(markB));
    for (int i = 0; i < MB; ++i) {
        cin >> SB[i];
        --SB[i];
        markB[SB[i]] = true;
    }

    TB.clear(); TB.resize(NB);
    for (int i = 0; i < NB-1; ++i) {
        int u,v;
        cin >> u >> v;
        --u, --v;
        TB[u].push_back(v);
        TB[v].push_back(u);
        if (markB[u] == false && markB[v] == false) {
            dsu_b.union_sets(u, v);
        }
    }

    ll specialA[NA];
    memset(specialA, 0, sizeof(specialA));
    for (int i = 0; i < MA; i++)
    {
        int sp = SA[i];
        specialA[sp] = 1;
        for (auto neighbor : TA[sp]) {
            if (markA[neighbor] == false) {
                specialA[sp] += dsu_a.find_size(neighbor);
            }
        }
    }

    ll non_specialA[NA];
    memset(non_specialA, 0, sizeof(non_specialA));
    for (int i = 0; i < NA; i++)
    {
        if (markA[i] == false) {
            int root_i = dsu_a.find(i);
            for (auto neighbor : TA[i]) {
                if (markA[neighbor] == true) {
                    non_specialA[i] += specialA[neighbor] - dsu_a.find_size(i);
                }
            }
            if (root_i != i) non_specialA[root_i] += non_specialA[i];
        }
    }

    ll specialB[NB];
    memset(specialB, 0, sizeof(specialB));
    for (int i = 0; i < MB; i++)
    {
        int sp = SB[i];
        specialB[sp] = 1;
        for (auto neighbor : TB[sp]) {
            if (markB[neighbor] == false) {
                specialB[sp] += dsu_b.find_size(neighbor);
            }
        }
    }

    ll non_specialB[NB];
    memset(non_specialB, 0, sizeof(non_specialB));
    for (int i = 0; i < NB; i++)
    {
        if (markB[i] == false) {
            int root_i = dsu_b.find(i);
            for (auto neighbor : TB[i]) {
                if (markB[neighbor] == true) {
                    non_specialB[i] += specialB[neighbor] - dsu_b.find_size(i);
                }
            }
            if (root_i != i) non_specialB[root_i] += non_specialB[i];
        }
    }

    ll ans = 0;
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < NA; ++i)
    {
        if (markA[i]) sumA += specialA[i];
        else {
            int root_i = dsu_a.find(i);
            sumA += non_specialA[root_i];
        }
        sumA %= mod;
    }

    for (int j = 0; j < NB; ++j)
    {
        if (markB[j]) sumB += specialB[j];
        else {
            int root_j = dsu_b.find(j);
            sumB += non_specialB[root_j];
        }
        sumB %= mod;
    }

    for (int i = 0; i < NA; ++i)
    {
        ll pathA = 0;
        if (markA[i] == false) {
            int root_i = dsu_a.find(i);
            pathA = non_specialA[root_i];
        }
        else pathA = specialA[i];

        ans += (pathA*(i+1)%mod)*sumB%mod;
        ans %= mod;
    }

    for (int j = 0; j < NB; ++j)
    {
        ll pathB = 0;
        if (markB[j] == false) {
            int root_j = dsu_b.find(j);
            pathB = non_specialB[root_j];
        }
        else pathB = specialB[j];

        ans += (pathB*(j+1)%mod)*sumA%mod;
        ans %= mod;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}