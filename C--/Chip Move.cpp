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
const ll mod = 998244353;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, k;
ll dp[maxn + 2], res[maxn + 2], S[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	cin >> n >> k;
	
	dp[0] = 1;
	for (int i = 0; i + k <= n; i += k, k++) {
		for (int j = 0; j <= k; ++j) S[j] = 0;
		
		for (int j = i; j <= n; ++j) {
			ll tmp = dp[j];
			dp[j] = S[j % k];
			S[j % k] = (S[j % k] + tmp) % mod;
			res[j] = (res[j] + dp[j]) % mod;
		}
	}
	
	for (int i = 1; i <= n; ++i) cout << res[i] % mod << " ";
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1716/D
