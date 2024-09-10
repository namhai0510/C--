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
const int maxn = 1e6;
const int maxa = 3e2;
const int base = 31;

ll n, a[maxa + 2], ans = 0;
ll dp[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i], dp[i][i] = a[i];
	
	for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            
            for (int k = i; k < j; ++k) {
                if (dp[i][k] == dp[k + 1][j])
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= n; ++j) ans = max(ans, dp[i][j]);
    	
    cout << ans << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
