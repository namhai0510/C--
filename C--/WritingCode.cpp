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
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, m, b, MOD;
ll a[maxn + 2];
ll dp[505][505], ans = 0;

void Input() {
	cin >> n >> m >> b >> MOD;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	dp[0][0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = a[i]; k <= b; ++k) {
				dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % MOD;
			}
		}
	}
	
	for (int x = 0; x <= b; ++x) ans += dp[m][x], ans %= MOD;
	
	cout << ans;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	Input();
	Process();    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/543/A
