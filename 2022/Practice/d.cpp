#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pii>> G(n);
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	for(auto &g : G) ranges::sort(g);

	vector<vector<ll>> pre(n);
	int sn = sqrt(n);
	for(int i = 0; i < n; ++i) if(G[i].size() > sn) {
		pre[i].assign(n, 0);
		for(auto [j, cj] : G[i]) {
			pre[i][j] += 2 * cj;
			for(auto [k, ck] : G[j]) {
				pre[i][k] += min(cj, ck);
			}
		}
	}

	while(q--) {
		int x, y;
		cin >> x >> y;
		--x;--y;
		if(G[x].size() > G[y].size()) swap(x, y);
		if(!pre[y].empty()) cout << pre[y][x] << ' ';
		else {
			ll ans = 0;
			for(auto [z, cz] : G[x]) {
				if(z == y) {
					ans += 2*cz;
					continue;
				}
				auto it = ranges::find(G[y], z, [](pii &p){ return p.first; });
				if(it == G[y].end()) continue;
				ans += min(cz, it->second);
			}
			cout << ans << ' ';
		}
	}
	cout << '\n';
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