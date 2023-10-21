#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int p; cin >> p;
	vi ans;
	int s = 0;
	for(int i = 2; i <= 41; ++i) while(p%i == 0) {
		p /= i;
		ans.push_back(i);
		s += i;
	}
	while(s < 41) {
		ans.push_back(1);
		++s;
	}
	if(s > 41 || p > 1) cout << "-1\n";
	else {
		cout << ans.size();
		for(int i : ans) cout << ' ' << i;
		cout << '\n';
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