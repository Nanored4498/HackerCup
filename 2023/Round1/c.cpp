#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for(char &c : s) c -= '0';
	int q; cin >> q;
	vector<bool> p(n, false);
	while(q--) {
		int b;
		cin >> b;
		--b;
		p[b] = !p[b];
	}
	for(int i = 0; i < n; ++i) if(p[i]) {
		for(int j = i; j < n; j += i+1) s[j] ^= 1;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) if(s[i]) {
		++ans;
		for(int j = i; j < n; j += i+1) {
			s[j] ^= 1;
		}
	}
	// for(char &c : s) c += '0';
	// cerr << s << endl;
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