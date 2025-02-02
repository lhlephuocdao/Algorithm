#include<bits/stdc++.h>

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

#define ll int
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
const int maxn = 4e5 + 5;
int Nx, Ny, Nz, t;
string Sx, Sy, Sz;

void build(set<tuple <ll, ll, ll> > &ans, string &s, int n) {
    vector <ll> a(3), m(3);

    FOR(i,0,n+1)
        //convert RGB -> 123
        if(s[i] == 'R') s[i] = 0;
        else if(s[i] == 'G') s[i] = 1;
        else s[i] = 2;

        //count the default case
        FOR(i,0,n)
            if(s[i] == s[i+1]) a[s[i]]++;
    
    ans.insert({a[0], a[1], a[2]});
    FOR(i,0,n+1)
        FOR(j,0,3) {
            if(s[i] != j) {
                vector<ll> m(a);
                if(i > 0) {
                    if(s[i] == s[i-1]) m[s[i]]--;
                    if(j == s[i-1]) m[j]++;
                }
                if(i < n) {
                    if(s[i] == s[i+1]) m[s[i]]--;
                    if(j == s[i+1]) m[j]++;
                }
                ans.insert({m[0], m[1], m[2]});
            }
        }
}

long long solve() {
    set<tuple <int, int, int>> x, y, z;
    cin >> Nx >> Ny >> Nz;
    cin >> Sx >> Sy >> Sz;

    build(x, Sx, Nx);
    build(y, Sy, Ny);
    build(z, Sz, Nz);

    long long ans = 0, temp = 0;
    for(auto [i0, i1, i2] : x)
        for(auto [j0, j1, j2] : y)
            for(auto [k0, k1, k2] : z) {
                temp = (long long) i0*j1*k2 + (long long) i0*j2*k1 + (long long) i1* j0*k2 + (long long) i1*j2*k0 + (long long) i2* j1*k0 + (long long) i2*j0*k1;
                if(temp > ans) ans = temp;
            }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long ans = solve();
        cout << ans << '\n';
    }

    return 0;
}