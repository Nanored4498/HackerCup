#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
constexpr int S = 41;

unordered_map<int, vi> sol;

vi a;
int s = 0, p = 1;
void part() {
	a.push_back(S - s);
	int p2 = p * a.back();
	if(!sol.count(p2) || sol[p2].size() > a.size()) sol[p2] = a;
	a.pop_back();
	for(int x = a.empty() ? 1 : a.back(); s + 2*x <= S; ++x) {
		a.push_back(x);
		s += x;
		p *= x;
		part();
		p /= x;
		s -= x;
		a.pop_back();
	}
}

void solve() {
	int p; cin >> p;
	if(sol.count(p)) {
		const vi ans = sol[p];
		cout << ans.size();
		for(int i : ans) cout << ' ' << i;
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	part();

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}