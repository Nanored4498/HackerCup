#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N;
		string S;
		cin >> N >> S;
		int i = 0;
		while(i < N && S[i] == 'F') ++i;
		if(i == N) {
			cout << "0\n";
			continue;
		}
		bool x = S[i] == 'X';
		int ans = 0;
		while(++i < N) {
			if((S[i] == 'X' && !x) || (S[i] == 'O' && x)) {
				++ ans;
				x = !x;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}