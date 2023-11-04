#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;
	a.resize(3*n);
	b.resize(3*n);
	for(int i = n; i < 3*n; ++i) {
		a[i] = b[i-n];
		b[i] = a[i-n];
	}
	vi ab(3*n+1, 0), ba(3*n+1, 0);
	for(int i = 0; i < 3*n; ++i) {
		ab[i+1] = ab[i] + (a[i] < b[i]);
		ba[i+1] = ba[i] + (b[i] < a[i]);
	}
	const int m = n/2;
	for(int i = n; i <= 3*n; ++i) {
		if(ab[i-n+m] - ab[i-n] == m && ba[i] - ba[i-m] == m) {
			if(n&1 && a[i-m-1] != b[i-m-1]) continue;
			bool ok = true;
			for(int j = 0; j < n; ++j) if(a[i-n+j] != b[i-1-j]) {
				ok = false;
				break;
			}
			if(ok) {
				cout << i-n << '\n';
				return;
			}
		}
	}
	cout << "-1\n";
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