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

ll n, k, a[405];
ll dp[405][405];
ll ps[405];

void Init() {
	for (int i = 0; i <= n; ++i)
    	for (int j = 0; j <= k + 1; ++j) dp[i][j] = +oo;
    dp[0][0] = 0;
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i];
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    Init();
    
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= k + 1; ++j) {
    		for (int x = 1; x <= i; ++x) {
    			ll val = -oo;
    			for (int x_ = x; x_ <= i; ++x_) val = max(val, a[x_]);
    			
    			dp[i][j] = min(dp[i][j], dp[x - 1][j - 1] + val * (i - x + 1) - (ps[i] - ps[x - 1]));
    		}
    	}
    	
    cout << dp[n][k + 1] << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hcm_thpt_23_b