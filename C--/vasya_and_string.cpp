#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, c[3][maxn + 2], ans = 0;
string s;

int main() {
    nothing
    if (fopen("vasya_and_string.inp", "r")) {
        freopen("vasya_and_string.inp", "r", stdin);
        freopen("vasya_and_string.out", "w", stdout);
    }
    cin >> n >> k >> s;
    
    s = '#' + s; 
    c[1][0] = 0; c[2][0] = 0; 
    c[1][n + 1] = +oo; c[2][n + 1] = +oo;
    
    for (int i = 1; i <= n; ++i) {
    	c[1][i] = c[1][i - 1];
    	c[2][i] = c[2][i - 1];
    	
    	c[s[i] - 'a' + 1][i]++;
    }
    
    // cout << s << endl;
    // for (int i = 1; i <= n; ++i) {
    	// cout << c[1][i] << " " << c[2][i] << endl;
    // }
    // cout << endl;
    
    ll l = 1, r = 0;
    for (l = 1; l <= n; ++l) {
    	if (r < n) {
	    	while (c[2][r + 1] - c[2][l - 1] <= k) {
	    		r++;
	    	}
	    }
	
    	if (c[2][r] - c[2][l - 1] <= k) ans = max(ans, r - l + 1);
    }
    
    r = 0;
    for (l = 1; l <= n; ++l) {
    	if (r < n) {
	    	while (c[1][r + 1] - c[1][l - 1] <= k) {
	    		r++;
	    	}
	    }
	
    	if (c[1][r] - c[1][l - 1] <= k) ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    
    return 0;
}