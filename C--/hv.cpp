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

ll n, k, a[maxa + 2][maxa + 2];
ll ps1[maxa + 2][maxa + 2], ps2[maxa + 2][maxa + 2];
ll ans = -oo;

int main() {
    nothing
    if (fopen("hv.inp", "r")) {
        freopen("hv.inp", "r", stdin);
        freopen("hv.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    memset(ps1, sizeof(ps1), 0);
    memset(ps2, sizeof(ps2), 0);
    
    for (int i = 1; i <= n + 1; ++i) {
    	for (int j = 1; j <= n + 1; ++j) {
    		ps1[i][j] = ps1[i - 1][j - 1] + a[i][j];
    	}
    	
    	for (int j = n + 1; j >= 1; --j) {
    		ps2[i][j] = ps2[i - 1][j + 1] + a[i][j];
    	}
    }
    
    // cout << endl;
    // for (int i = 0; i <= n + 1; ++i) {
    	// for (int j = 0; j <= n + 1; ++j) {
    		// cout << ps1[i][j] << " ";
    	// }
    	// cout << endl;
    // }
    
    for (int i = 1; i <= n - k + 1; ++i) {
    	for (int j = 1; j <= n - k + 1; ++j) {
    		ll s1 = ps1[i + k - 1][j + k - 1] - ps1[i - 1][j - 1];
    		ll s2 = ps2[i + k - 1][j] - ps2[i - 1][j + k];
    		// cout << s1 << " " << s2 << " " << a[i + (k + 1) / 2 - 1][j + (k + 1)/ 2 - 1] << endl;
    		ll res = s1 + s2;
    		
    		if (k % 2 == 0) {
    			// cout << res << endl;
    			ans = max(ans, res);
    		}
    		else {
    			// cout << res - a[i + (k + 1) / 2 - 1][j + (k + 1)/ 2 - 1] << endl;
    			ans = max(ans, res - a[i + (k + 1) / 2 - 1][j + (k + 1)/ 2 - 1]);
    		}
    	}
    }
    
    cout << ans << endl;
    return 0;
}
