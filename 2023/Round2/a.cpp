#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int r, c;
vector<string> m;
vector<vector<bool>> seen;
int li, lj, nw;

pii adj[] {{1,0}, {-1,0}, {0,1}, {0,-1}};

int f(int i, int j) {
	seen[i][j] = true;
	++nw;
	int ans = 0;
	for(const auto &[x, y] : adj) {
		int u = i+x;
		int v = j+y;
		if(u < 0 || u >= r) continue;
		if(v < 0 || v >= c) continue;
		if(m[u][v] == '.' && (u != li || v != lj)) {
			li = u;
			lj = v;
			++ ans;
		} else if(m[u][v] == 'W' && !seen[u][v]) {
			ans += f(u, v);
		}
	}
	return ans;
}

void solve() {
	cin >> r >> c;
	m.resize(r);
	for(string &s : m) cin >> s;
	vector<vi> count(r, vi(c, 0));
	seen.assign(r, vector<bool>(c, false));
	int ans = 0;
	for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(m[i][j] == 'W' && !seen[i][j]) {
		li = lj = -1;
		nw = 0;
		if(f(i, j) == 1) {
			count[li][lj] += nw;
			ans = max(ans, count[li][lj]);
		}
	}
	// if(ans) cout << "YES\n";
	// else cout << "NO\n";
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}