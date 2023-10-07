#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n; cin >> n;
	vector<ll> a(2*n-1);
	for(ll &x : a) cin >> x;
	if(n == 1) {
		cout << "1\n";
		return;
	}
	ranges::sort(a);
	ll S = accumulate(a.begin(), a.end(), 0LL);
	ll ans = -1;
	for(ll s : {a[0]+a[2*n-2], a[0]+a[2*n-3], a[1]+a[2*n-2]}) {
		auto b = a;
		ll x = n*s - S;
		if(x < 1) continue;
		b.push_back(x);
		ranges::sort(b);
		bool ok = true;
		for(int i = 0; i < n; ++i) if(b[i]+b[2*n-1-i] != s) ok = false;
		if(ok && (ans == -1 || x < ans)) ans = x;
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