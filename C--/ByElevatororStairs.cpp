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
const int maxa = 2e3 + 5;
const int base = 31;

ll n, c;
ll a[maxn + 2], b[maxn + 2];
ll dp[3][maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> c;
    
    for (int i = 1; i <= n - 1; ++i) cin >> a[i];
    for (int i = 1; i <= n - 1; ++i) cin >> b[i];
    
    for (int i = 1; i <= n; ++i) dp[0][i] = dp[1][i] = +oo;
    dp[0][1] = 0;
    dp[1][1] = c;
    
	for (int i = 1; i <= n - 1; ++i) {
		dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + a[i]);
		dp[0][i + 1] = min(dp[0][i + 1], dp[0][i] + a[i]);
		dp[1][i + 1] = min(dp[1][i + 1], dp[1][i] + b[i]);
		dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + b[i] + c);
	}
	
	for (int i = 1; i <= n; ++i) cout << min(dp[0][i], dp[1][i]) << " ";
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1249/E