#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n; cin >> n;
	vector<double> x(n);
	for(double &x : x) cin >> x;
	sort(x.begin(), x.end());
	if(n == 5) {
		double a = (x[0]+x[2])/2;
		double b = (x[n-2]+x[n-1])/2;
		double ans = b-a;
		a = (x[0]+x[1])/2;
		b = (x[n-1]+x[n-3])/2;
		cout << max(ans, b-a) << '\n';
	} else {
		double a = (x[0]+x[1])/2;
		double b = (x[n-2]+x[n-1])/2;
		cout << (b-a) << '\n';
	}
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