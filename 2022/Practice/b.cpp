#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

pii adj[4] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int r, c;
		cin >> r >> c;
		vector<string> m(r), ans(r);
		vector<vi> count(r, vi(c, 0));
		for(string &s : m) cin >> s;
		for(int i = 0; i < r; ++i) {
			ans[i] = m[i];
			for(char &c : ans[i]) if(c == '.') c = '^';
		}
		vector<pii> Q;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(ans[i][j] != '^') continue;
				int n = 0;
				for(const pii &a : adj) {
					int x = i+a.first;
					if(x < 0 || x >= r) continue;
					int y = j+a.second;
					if(y < 0 || y >= c) continue;
					if(ans[x][y] == '^') ++ n;
				}
				count[i][j] = n;
				if(n < 2) Q.emplace_back(i, j);
			}
		}
		bool bad = false;
		while(!Q.empty()) {
			auto [i, j] = Q.back();
			Q.pop_back();
			if(ans[i][j] != '^') continue;
			if(m[i][j] == '^') bad = true;
			ans[i][j] = '.';
			for(const pii &a : adj) {
				int x = i+a.first;
				if(x < 0 || x >= r) continue;
				int y = j+a.second;
				if(y < 0 || y >= c) continue;
				if(ans[x][y] == '^') {
					if(--count[x][y] < 2) {
						Q.emplace_back(x, y);
					}
				}
			}
		}

		if(bad) cout << "Impossible\n";
		else {
			cout << "Possible\n";
			for(string &s : ans) cout << s << '\n';
		}
	}

	return 0;
}