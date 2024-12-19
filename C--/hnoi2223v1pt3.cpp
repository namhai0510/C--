#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e9;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 1e5;
const int base = 31;

ll n, a[maxn + 2];
ll S = 0;
ll dp[3][2 * maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i], S += a[i];
    
    for (int i = 0; i <= 2 * maxa; ++i)
    	dp[0][i] = dp[1][i] = +oo;
    
    dp[0][maxa] = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= 2 * maxa; ++j) {
    		if (j + a[i] <= 2 * maxa)
    			dp[1][j] = min(dp[1][j], dp[0][j + a[i]]);
    		if (j - a[i] >= 0)
    			dp[1][j] = min(dp[1][j], dp[0][j - a[i]]);
    			
    		dp[1][j] = min(dp[1][j], dp[0][j] + a[i]);
    	}
    	
    	for (int j = 0; j <= 2 * maxa; ++j) {
    		dp[0][j] = dp[1][j];
    		dp[1][j] = +oo;
    	}
    }
    
    cout << (S - dp[0][maxa]) / 2;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
