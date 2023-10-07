#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int C = 256;
	bool v[C];
	for(int i = 0; i < C; ++i) v[i] = false;
	v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = true;

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		string S;
		cin >> S;
		int ans = 2*S.size();
		for(char c = 'A'; c <= 'Z'; ++c) {
			int a = 0;
			for(char s : S)
				if(v[s] != v[c]) a += 1;
				else if(s != c) a += 2;
			ans = min(ans, a);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}