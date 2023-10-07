#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

vector<vi> G;
vi C;

void dfs(int i, int p=-1) {
	int m = 0;
	for(int j : G[i]) if(j != p) {
		dfs(j, i);
		m = max(m, C[j]);
	}
	C[i] += m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		C.resize(N);
		for(int &x : C) cin >> x;
		G.resize(N);
		for(vi &g : G) g.clear();
		for(int i = 1; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			G[--a].push_back(--b);
			G[b].push_back(a);
		}

		int ans = C[0];
		dfs(0);
		sort(G[0].begin(), G[0].end(), [&](int i, int j) { return C[i] > C[j]; });
		if(0 < G[0].size()) ans += C[G[0][0]];
		if(1 < G[0].size()) ans += C[G[0][1]];
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}