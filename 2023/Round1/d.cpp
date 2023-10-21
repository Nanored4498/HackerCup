#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;

vector<pair<pii, pii>> a;
vector<bool> inv;
int l, r;

void f(int i, int x, int y) {
	if(y < l || x > r) return;
	if(l <= x && y <= r) {
		inv[i] = !inv[i];
		swap(a[i].first, a[i].second);
	} else {
		int z = (x+y)/2;
		f(2*i, x, z);
		f(2*i+1, z+1, y);
		a[i] = { max(a[2*i].first, a[2*i+1].first), max(a[2*i].second, a[2*i+1].second) };
		if(inv[i]) swap(a[i].first, a[i].second);
	}
}

void solve() {
	int n;
	cin >> n;
	int s = 1;
	while(s < n) s <<= 1;
	a.assign(s << 1, {{0, 0}, {0, 0}});
	inv.assign(s << 1, false);
	for(int i = 0; i < n; ++i) {
		cin >> a[s+i].first.first;
		a[s+i].second.first = MOD - a[s+i].first.first;
		a[s+i].first.second = a[s+i].second.second = - (i+1);
	}
	for(int i = s-1; i > 0; --i)
		a[i] = { max(a[2*i].first, a[2*i+1].first), max(a[2*i].second, a[2*i+1].second) };

	ll ans = 0;
	int q;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		--l; --r;
		f(1, 0, s-1);
		ans -= a[1].first.second;
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