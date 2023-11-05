#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

struct UF {
	vector<int> r;
	UF(int n): r(n, -1) {}
	int find(int i) {
		if(r[i] < 0) return i;
		return r[i] = find(r[i]);
	}
	void merge(int i, int j) {
		i = find(i); j = find(j);
		if(i == j) return;
		if(r[i] > r[j]) swap(i, j);
		r[i] += r[j];
		r[j] = i;
	}
};

int n, m;
vector<pii> a;
vi tmp;
vector<vector<vi>> b;

void f(int i=0, int s=0) {
	if(i == a.size()) b[s].push_back(tmp);
	else {
		for(int j = 0; j <= a[i].second; ++j) {
			tmp[i] = j;
			f(i+1, s);
			s += a[i].first;
		}
	}
}

void solve() {
	cin >> n >> m;
	UF uf(n);
	while(m--) {
		int a, b;
		cin >> a >> b;
		uf.merge(a-1, b-1);
	}
	vi s;
	for(int i = 0; i < n; ++i)
		if(uf.r[i] < 0)
			s.push_back(-uf.r[i]);
	ranges::sort(s);
	a.clear();
	for(int x : s) {
		if(a.empty() || a.back().first != x) a.emplace_back(x, 0);
		++ a.back().second;
	}
	int na = a.size();
	b.clear();
	b.resize(n+1);
	tmp.resize(na);
	f();
	for(int k = 1; k <= n; ++k) if(n%k == 0) {
		int t = n/k;
		set<vi> u, v;
		u.insert(vi(na, 0));
		for(const vi &x : b[t]) {
			v = u;
			for(vi y : u) {
				while(true) {
					bool ok = true;
					for(int j = 0; j < na; ++j) {
						if((y[j] += x[j]) > a[j].second) {
							ok = false;
							break;
						}
					}
					if(ok) v.insert(y);
					else break;
				}
			}
			u = move(v);
			if(u.count(b[n][0])) break;
		}
		if(u.count(b[n][0])) cout << k << ' ';
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