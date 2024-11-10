#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 998244353;
const ll mod = 1e9 + 7;
const int maxn = 1e5;
const int maxa = 2e3;
const int base = 31;

ll n, a[2 * maxn + 2];
ll dp[3][2 * maxn + 2], res = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	dp[0][maxn] = 1;
	for (int x = 2; x + 1 <= n; ++x) {
		for (int i = 1; i <= maxn * 2; ++i) dp[1][i] = 0;

    	for (int i = 1; i <= maxn * 2; ++i) {
		    if (dp[0][i] == 0) continue;
		    
		    int nxt = a[x] + i;
		    dp[1][nxt] = (dp[1][nxt] + dp[0][i]) % mod;
		    if (nxt != maxn)
		        dp[1][2 * maxn - nxt] = (dp[1][2 * maxn - nxt] + dp[0][i]) % mod;
		}
		
		for(int i = 1; i <= maxn * 2; i++)
		    dp[0][i] = dp[1][i];
	}
	    
	for(int i = 1; i <= maxn * 2; ++i)
        res = (res + dp[0][i]) % mod;
        
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1783/D
