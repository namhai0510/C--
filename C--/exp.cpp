#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 7e3 + 5;
const int base = 31;

ll n, dp[maxn + 2], f[maxn + 2], res = 0;

void Solve() {
	for (int i = 1; i <= 5; ++i) dp[i] = i;
	
	for (int i = 6; i <= maxa; ++i) {
		dp[i] = i;
		for (int j = 1; j * j <= i; ++j) {
			if (i % j != 0) continue;
			ll x = j;
			dp[i] = min(dp[i], dp[x] + 2 + dp[i / x]);
			x = i / j;
			dp[i] = min(dp[i], dp[x] + 2 + dp[i / x]);
		}
	}

	for (int i = 1; i <= maxa; ++i) {
		f[i] = dp[i];
		for (int j = 1; j < i; ++j) f[i] = min(f[i], dp[j] + 2 + dp[i - j]);
	}
}

int main() {
    nothing
    if (fopen("exp.inp", "r")) {
        freopen("exp.inp", "r", stdin);
        freopen("exp.out", "w", stdout);
    }
    Solve();
    
    while (cin >> n){
		res = f[n];
		for (int i = 1; i <= n; ++i) {
			res = min(res, f[i] + 2 + f[n - i]);
		}
		cout << res << endl;
	}
	
    return 0;
}
