#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("out.txt", "w", stdout);
	string heard; cin >> heard;
    // mildredree
	int n = 0; // number of unique letters

	map<char,int> index;
	for (char letter: heard)
        if (!index.count(letter))
            index[letter] = n++;
            /*
                index['m'] = 0
                index['i'] = 1
                index['l'] = 2
                index['d'] = 3
                index['r'] = 4
                index['e'] = 5
            */


	vector<vector<int>> adjacent(n, vector<int>(n));
	for (int k = 1; k < heard.size(); ++k) {
        cout << "k: " << k << " heard[" << k-1 << "] : " << heard[k-1] << " heard[" << k << "] : " << heard[k] << '\n';
        int i = index[heard[k-1]];
        int j = index[heard[k]];
		adjacent[i][j]++;
        cout << "adjacent[" << i << "][" << j << "]: " << adjacent[i][j] << '\n';
    }
	cout << '\n';

	vector<int> p(n); iota(begin(p), end(p), 0); // 0 ... n-1
	int ans = INT_MAX;
	do {
		for (auto x : p) cout << char(x +'a') << " ";
		cout << '\n';
		int cur_ans = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j) {
				cur_ans += adjacent[p[i]][p[j]];
				cout << "i: " << i << " j: " << j << '\n';
				cout << "p[i]: " << p[i] << " p[j]: " << p[j] << '\n';
				cout << "adjacent[p[i]][p[j]]: " << adjacent[p[i]][p[j]] << '\n';
			}
		cout << "cur_ans: " << cur_ans << '\n';
		cout << '\n';
		// now cur_ans = evaluate(p)
		ans = min(ans, cur_ans);
		// mildrEabcfghjknopqstuvwxyz
	} while (next_permutation(begin(p), end(p)));

	cout << ans << "\n";
}