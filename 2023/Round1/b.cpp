#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
constexpr int S = 41;

map<vi, vi> mem;

vi f(vi &a, int s) {
	ranges::sort(a);
	auto it = mem.lower_bound(a);
	if(it == mem.end() || it->first != a) {
		it = mem.emplace_hint(it, a, a);
		int s2;
		int score = S-s + a.size();
		for(int i = 1; i < (int) a.size(); ++i) {
			for(int j = 0; j < i && (s2 = s + a[i]*a[j] - a[i] - a[j]) <= S; ++j) {
				vi b(a.size()-1);
				auto w = copy(a.begin(), a.begin()+j, b.begin());
				w = copy(a.begin()+j+1, a.begin()+i, w);
				w = copy(a.begin()+i+1, a.end(), w);
				*w = a[i]*a[j];
				vi c = f(b, s2);
				const int score2 = S-accumulate(c.begin(), c.end(), 0) + c.size();
				if(score2 < score) {
					it->second = move(c);
					score = score2;
				}
			}
		}
	}
	return it->second;
}

void solve() {
	int p; cin >> p;
	vi ans;
	int s = 0;
	for(int i = 2; i <= S; ++i) while(p%i == 0) {
		p /= i;
		ans.push_back(i);
		s += i;
	}
	if(s > S || p > 1) {
		cout << "-1\n";
		return;
	}
	ans = f(ans, s);
	s = accumulate(ans.begin(), ans.end(), 0);
	while(s < S) {
		ans.push_back(1);
		++s;
	}
	cout << ans.size();
	for(int i : ans) cout << ' ' << i;
	cout << '\n';
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