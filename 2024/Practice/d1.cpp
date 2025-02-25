#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n, g;
	cin >> n >> g;
	vector<int> E(n);
	for(int &x : E) cin >> x;
	sort(E.begin(), E.end());
	int ind = lower_bound(E.begin(), E.end(), g) - E.begin();
	if(ind == n || (ind && abs(E[ind-1] - g) < abs(E[ind] - g))) {
		--ind;
	} else {
		while(ind+1 < n && E[ind+1] == E[ind]) ++ind;
	}
	int dist = abs(E[ind] - g);
	ind = n - ind;
	cout << ind << ' ' << dist << '\n';
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