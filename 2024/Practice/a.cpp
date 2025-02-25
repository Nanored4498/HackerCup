#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> s(n);
	for(ll &x : s) cin >> x;
	const ll y = max(1, 2*n-3) * *min_element(s.begin(), s.end());
	if(y <= k) cout << "YES\n";
	else cout << "NO\n";
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