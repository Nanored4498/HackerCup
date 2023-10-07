#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n;
	string c;
	cin >> n >> c;
	char d[] = ".-";
	char f = c[0] == '.' ? '-' : '.';
	cout << '\n';
	while(--n) {
		cout << f;
		for(int i = 0; i < 9; ++i) cout << d[(n>>i)&1];
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