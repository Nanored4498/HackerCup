#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for(int &x : a) {
		cin >> x;
		x %= m;
	}
	vi b(n+1, 0);
	for(int i = 0; i < n; ++i) b[i+1] = b[i] + a[i];
	int p = 1;
	while(p <= m) p <<= 1;
	vector<vi> g(n+1, vi(m, n));
	for(int i = n-1; i >= 0; --i) {
		g[i] = g[i+1];
		for(int j = i; j < n; ++j) {
			int x = (b[j+1] - b[i]) % m;
			g[i][x] = min(g[i][x], j);
		}
	}
	int ans = 0;
	vi dist(p, n+1);
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.emplace(dist[0] = 0, 0);
	while(!Q.empty()) {
		auto [i, x] = Q.top();
		Q.pop();
		if(dist[x] != i) continue;
		++ ans;
		for(int y = 0; y < m; ++y) if(g[i][y] < n) {
			int z = x^y;
			if(dist[z] > g[i][y]+1) {
				Q.emplace(dist[z] = g[i][y]+1, z);
			}
		}
	}
	cout << ans << '\n';
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