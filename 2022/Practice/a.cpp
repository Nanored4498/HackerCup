#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int n, k;
		cin >> n >> k;
		vi s(101, 0);
		string ans = "YES";
		if(n > 2*k) ans = "NO";
		while(n--) {
			int x; cin >> x;
			if(++s[x] > 2) ans = "NO";
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}