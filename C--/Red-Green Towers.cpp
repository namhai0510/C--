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
const ll mod = 1e9 + 7;
const int maxn = 2e5;
const int maxa = 2e3;
const int base = 31;

ll r, g;
ll total, mx, res = 0, dp[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	cin >> r >> g;
	
	if (r > g) swap(r, g);
	
	total = (r + g) * 2;
	mx = sqrt(total);
	
	while (mx * (mx + 1) > total) mx--;
	
	dp[0] = 1;
	for (int i = 1; i <= mx; ++i)
        for (int j = r; j >= i; --j)
            dp[j] = (dp[j] + dp[j - i]) % mod;
            
    for (int i = 0; i <= r; ++i)
    	if (i + g >= mx * (mx + 1) / 2) 
    		res += dp[i], res %= mod;
    		
    cout << res << endl;
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
 
// https://codeforces.com/problemset/problem/478/D