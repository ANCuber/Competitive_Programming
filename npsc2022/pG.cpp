#include <bits/stdc++.h>
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
#define safe() std::cerr << "\033[1;32m" << __PRETTY_FUNCTION__ << " is safe\033[0m\n"
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
FILE* setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 1005, MAXM = 1005;
const ll INF = 1e18 + 7;
ll a[MAXN], b[MAXM];
ll prea[MAXN], preb[MAXM];
bool dp[MAXN][MAXM];
int N, M;
bool check(ll k) { // k is max
	for(int i = 0; i <= N; ++i) {
		for(int j = 0; j <= M; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	dp[1][0] = (a[1] >= 0 && a[1] <= k);
	dp[0][1] = (b[1] >= 0 && b[1] <= k);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			dp[i][j] = 0;
			ll val = prea[i] + preb[j];
			if(val < 0 || val > k) continue;
			dp[i][j] |= dp[i - 1][j];
			dp[i][j] |= dp[i][j - 1];
		}
	}
	return dp[N][M];
}
void solve() {
	cin >> N >> M;
	prea[0] = 0, preb[0] = 0;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		prea[i] = a[i] + prea[i - 1];
	}
	for(int i = 1; i <= M; ++i) {
		cin >> b[i];
		preb[i] = b[i] + preb[i - 1];
	}
	ll l = -1, r = INF;
	while(r - l > 1) {
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
		//debug(mid);
	}
	if(r == INF) cout << "-1\n";
	else cout << r << '\n';
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}


