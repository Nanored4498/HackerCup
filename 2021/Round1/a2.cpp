#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		ll N;
		string S;
		cin >> N >> S;
		ll i = 0;
		while(i < N && S[i] == 'F') ++i;
		if(i == N) {
			cout << "0\n";
			continue;
		}
		bool x = S[i] == 'X';
		ll last = i;
		ll ans = 0;
		while(++i < N) {
			if((S[i] == 'X' && !x) || (S[i] == 'O' && x)) {
				ans = (ans + (last+1) * (N-i)) % MOD;
				x = !x;
			}
			if(S[i] != 'F') last = i;
		}
		cout << ans << '\n';
	}

	return 0;
}