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

ll test;
ll n, a[maxn + 2];
ll dp[maxn + 2], cnt, g;

ll Pow(ll x, ll k) {
	ll ret = 1;
	
	for (ll num = x, t = k; t; num = num * num % mod, t >>= 1) {
        if (t & 1) {
            ret = ret * num % mod;
        }
    }
    
    return ret % mod;
}

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i], dp[i] = 0;	
}

void Process() {
	cnt = g = 0;
	for (int i = 1; i <= n; ++i) 
		if (a[i] == 0) g++;
	for (int i = 1; i <= g; ++i)
		if (a[i] == 0) cnt++;
		
	dp[g + 1] = 0;
	for (int i = g; i >= 1; --i) {
		dp[i] = dp[i + 1] % mod;
		dp[i] += n * (n - 1) % mod * 
				 Pow(2, mod - 2) % mod * 
				 Pow(g - i + 1, mod - 2) % mod * 
				 Pow(g - i + 1, mod - 2) % mod;
				
		dp[i] %= mod;
	}
	
	cout << dp[cnt + 1] << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1753/C
