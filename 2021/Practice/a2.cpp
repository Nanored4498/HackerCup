#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		string S;
		int K;
		cin >> S >> K;

		const int C = 26;
		vector<vi> d(C, vi(C, C));
		for(int i = 0; i < C; ++i) d[i][i] = 0;
		while(K--) {
			char a, b;
			cin >> a >> b;
			d[a-'A'][b-'A'] = 1;
		}
		for(int i = 0; i < C; ++i)
			for(int j = 0; j < C; ++j)
				for(int k = 0; k < C; ++k)
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

		const int M = C*S.size();
		int ans = M;
		for(int c = 0; c < C; ++c) {
			int a = 0;
			for(char s : S)
				if(d[s-'A'][c] == C) {
					a = M;
					break;
				} else a += d[s-'A'][c];
			ans = min(ans, a);
		}
		if(ans == M) ans = -1;
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}