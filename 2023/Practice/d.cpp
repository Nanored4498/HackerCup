#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

int n, m, q;
vector<vi> G;

vector<vi> G2, Parents;
vi Comp, Root, Depth;
vi in, stack;
int t, c;

int dfs(int i, int p = -1) {
	int low = in[i] = ++t;
	for(int j : G[i]) {
		if(j == p) continue;
		if(in[j]) low = min(low, in[j]);
		else low = min(low, dfs(j, i));
	}
	if(low == in[i]) {
		while(!stack.empty() && in[stack.back()] > in[i]) {
			Comp[stack.back()] = c;
			stack.pop_back();
		}
		Comp[i] = c ++;
		Root.push_back(i);
		Parents.emplace_back(1, p);
	} else stack.push_back(i);
	return low;
}

void tarjan() {
	Comp.resize(n);
	Root.clear();
	Parents.clear();
	in.assign(n, t = 0);
	stack.clear();
	c = 0;
	dfs(0);
	G2.resize(c);
	for(vi &g : G2) g.clear();
	Parents.back().pop_back();
	Depth.resize(c);
	Depth.back() = 0;
	for(int i = c-2; i >= 0; --i) {
		const int j = Comp[Parents[i][0]];
		Parents[i][0] = j;
		Depth[i] = Depth[j] + 1;
		G2[i].push_back(j);
		G2[j].push_back(i);
	}
}

vi color;
vector<bool> odd;

bool dfs2(int i, int c) {
	color[i] = c;
	for(int j : G[i]) if(Comp[j] == Comp[i])
		if(color[j]) {
			if(color[j] == c) return false;
		} else {
			if(!dfs2(j, c^2)) return false;
		}
	return true;
}

void loop() {
	color.assign(n, 0);
	odd.resize(c);
	for(int i = 0; i < c; ++i) {
		odd[i] = !dfs2(Root[i], 1);
	}
}

void solve() {
	cin >> n >> m;
	G.resize(n);
	for(vi &g : G) g.clear();
	while(m--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	tarjan();
	loop();
	vi dist(c, -1), Q;
	for(int i = 0; i < c; ++i) if(odd[i]) {
		Q.push_back(i);
		dist[i] = 0;
	}
	cin >> q;

	if(Q.empty()) {
		int ans = -q;
		while(q--) {
			int a, b;
			cin >> a >> b;
		}
		cout << ans << '\n';
		return;
	}

	for(int i = 0; i < c; ++i) {
		const int j = Q[i];
		for(int k : G2[j]) if(dist[k] == -1) {
			dist[k] = dist[j]+1;
			Q.push_back(k);
		}
	}

	vector<vi> md(c);
	for(int i = c-2; i >= 0; --i) {
		md[i].push_back(min(dist[i], dist[Parents[i][0]]));
		int k = 0;
		while(k < (int) md[Parents[i][k]].size()) {
			Parents[i].push_back(Parents[Parents[i][k]][k]);
			md[i].push_back(min(md[i][k], md[Parents[i][k]][k]));
			++k;
		}
	}

	ll ans = 0;
	while(q--) {
		int a, b;
		cin >> a >> b;
		a = Comp[a-1];
		b = Comp[b-1];
		int d = dist[a];
		if(Depth[a] < Depth[b]) swap(a, b);
		int k = Parents[a].size()-1;
		while(Depth[a] > Depth[b]) {
			while(Depth[a] - (1<<k) < Depth[b]) --k;
			d = min(d, md[a][k]);
			a = Parents[a][k];
		}
		k = Parents[a].size()-1;
		while(a != b) {
			while(Depth[a] < (1<<k)) --k;
			while(k && Parents[a][k] == Parents[b][k]) --k;
			d = min(d, md[a][k]);
			d = min(d, md[b][k]);
			a = Parents[a][k];
			b = Parents[b][k];
		}
		ans += d;
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