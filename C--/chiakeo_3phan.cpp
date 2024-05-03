#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

int n, a[maxn + 2], total = 0, ans = 0;
bool dp[34][642][642];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	total += a[i];
    }
    
    for (int i = 0; i <= n; ++i) dp[i][0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= total / 3 + 20; ++j) {
    		for (int k = 0; k <= total / 3 + 20; ++k) {
    			dp[i][j][k] = dp[i - 1][j][k];
    			
    			if (j >= a[i - 1])
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - a[i - 1]][k];
                if (k >= a[i - 1])
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - a[i - 1]];
    		}
    	}
    }
    
    ans = total;
    for (int j = 0; j <= total / 3 + 20; ++j) {
        for (int k = 0; k <= total / 3 + 20; ++k) {
            if (dp[n][j][k]) {
                int mx = max({j, k, total - j - k});
                int mn = min({j, k, total - j - k});
                ans = min(ans, mx - mn);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
