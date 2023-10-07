#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	ll A, B, C, K;
	cin >> A >> B >> C;
	if(B < 2*A) {
		ll b = C/B;
		C -= b*B;
		ll a = C/A;
		K = max(0LL, 2*(b+a)-1);
	} else {
		ll a = C/A;
		K = a;
	}
	cout << K << '\n';
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