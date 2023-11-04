#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

template <int MOD>
struct mint {
	typedef long long ll;
	static const int mod = MOD;
	int x;
	constexpr mint(): x(0) {}
	constexpr mint(ll v) {
		x = v % mod;
		if(x < 0) x += mod;
	}

	friend mint pow(mint a, ll p) {
		mint ans = 1;
		for(; p; p >>= 1, a *= a) if(p&1) ans *= a;
		return ans;
	}
	friend mint inv(mint a) { return pow(a, mod-2); }

	explicit operator int() const { return x; }
	friend bool operator==(const mint &a, const mint &b) { return a.x == b.x; }
	friend bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }
	friend bool operator<=(const mint &a, const mint &b) { return a.x <= b.x; }
	friend bool operator<(const mint &a, const mint &b) { return a.x < b.x; }
	friend ostream& operator<<(ostream &stream, const mint &v) { return stream << v.x; }
	friend istream& operator>>(istream &stream, mint &v) { return stream >> v.x; }
	mint& operator+=(const mint &b) { if((x += b.x) >= mod) x -= mod; return *this; }
	mint& operator-=(const mint &b) { if((x -= b.x) < 0) x += mod; return *this; }
	mint& operator*=(const mint &b) { x = (1LL * x * b.x) % mod; return *this; }
	mint& operator/=(const mint &b) { return (*this) *= inv(b); }
	mint& operator%=(const mint &b) { x %= b.x; return *this; }
	mint& operator++() { return (*this) += 1; }
	mint& operator--() { return (*this) -= 1; }
	mint operator-() { return -x; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};
const int MOD = 1e9+7;
using mi = mint<MOD>;

const int MAX = 1e6+5;
vector<int> p(MAX, 0);
vector<mi> fact(MAX, 1);

void solve() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<mi> a(MAX, 0);
	while(n--) {
		int h;
		cin >> h;
		vector<int> ds(1, 1);
		while(h > 1) {
			int q = p[h];
			ll qe = 1;
			while(p[h] == q) {
				qe *= q;
				h /= q;
			}
			int s = ds.size();
			for(ll qj = q; qj <= qe; qj *= q)
				for(int i = 0; i < s; ++i)
					ds.push_back(ds[i] * qj);
		}
		for(int d : ds) {
			++ a[d];
		}
	}
	mi ans = 0;
	for(int i = MAX-1; i >= 1; --i) {
		if((int) a[i] >= k) {
			a[i] = fact[(int) a[i]] / fact[(int) a[i] - k];
			for(int j = i+i; j < MAX; j += i) a[i] -= a[j];
		} else {
			a[i] = 0;
		}
		if(d % i == 0) ans += a[i];
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 2; i < MAX; ++i) if(!p[i]) {
		for(int j = i; j < MAX; j += i)
			p[j] = i;
	}
	for(int i = 2; i < MAX; ++i) fact[i] = fact[i-1] * i;

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}