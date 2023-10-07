#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vi rx(N, 0), ro(N, 0), rp(N);
		vi cx(N, 0), co(N, 0), cp(N);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j) {
				char c;
				cin >> c;
				if(c == 'X') {
					++ rx[i];
					++ cx[j];
				} else if(c == 'O') {
					++ ro[i];
					++ co[j];
				} else {
					rp[i] = j;
					cp[j] = i;
				}
			}
		int ans = N+1, count = 0;
		set<int> count1;
		for(int i = 0; i < N; ++i) {
			if(ro[i] == 0)
				if(ans > N-rx[i]) {
					ans = N-rx[i];
					count = 1;
					count1 = {i+rp[i]*N};
				} else if(ans == N-rx[i]) {
					++ count;
					count1.insert(i+rp[i]*N);
				}
			if(co[i] == 0)
				if(ans > N-cx[i]) {
					ans = N-cx[i];
					count = 1;
					count1 = {cp[i]+i*N};
				} else if(ans == N-cx[i]) {
					++ count;
					count1.insert(cp[i]+i*N);
				}
		}
		if(ans == 1) count = count1.size();
		if(count == 0) cout << "Case #" << t << ": Impossible\n";
		else cout << "Case #" << t << ": " << ans << ' ' << count << '\n';
	}

	return 0;
}