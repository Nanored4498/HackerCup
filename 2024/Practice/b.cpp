#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n, p;
	cin >> n >> p;
	double q = (double) p / 100;
	double ans = 100.*pow(q, double(n-1) / n) - p;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	cout << fixed << setprecision(8);
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}