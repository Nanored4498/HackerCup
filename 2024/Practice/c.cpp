#include <iostream>
#include <vector>
#include <random>

using namespace std;
using ll = long long;

mt19937 mt(42);

void solve() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> P(n);
	for(auto &[x, y] : P) cin >> x >> y;
	int ma = 0;
	for(int k = 0; k < 100; ++k) {
		int i = mt() % n;
		int j = (i + 1 + (mt() % (n-1))) % n;
		ll ux = P[j].first - P[i].first;
		ll uy = P[j].second - P[i].second;
		const ll d = ux * P[i].second - uy * P[i].first;
		int a = 0;
		for(const auto &[x, y] : P) if(ux * y - uy * x == d) ++ a;
		ma = max(ma, a);
	}
	cout << n - ma << '\n';
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