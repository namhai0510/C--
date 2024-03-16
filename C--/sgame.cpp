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
const int maxa = 3e2 + 52;

ll t, n, k, red = 0;
string s;

bool dp[maxa + 5][maxa + 5][maxa + 5];
ll ps[maxn + 2];

void Reset() {
	ps[0] = 0;
	for (int i = 0; i <= maxa; ++i) {
		for (int j = 0; j <= maxa; ++j) {
			for (int k = 0; k <= maxa; ++k) dp[i][j][k] = 0;
		}
	}
}
int main() {
    nothing
    if (fopen("sgame.inp", "r")) {
        freopen("sgame.inp", "r", stdin);
        freopen("sgame.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n >> k;
    	cin >> s;
    	
    	s = '#' + s;
    	
    	Reset();
    	
    	for (int i = 1; i <= n; ++i) {
    		ps[i] = ps[i - 1];
    		if (s[i] == 'R') ps[i]++;
    	}
    	red = ps[n];
    	
    	for (int l = n; l >= 1; --l) {
    		for (int r = l; r <= n; ++r) {
    			for (int m = red; m >= 0; --m) {
    				ll h = red - (m + ps[r] - ps[l - 1]);
    				
    				if (m >= k) dp[l][r][m] = 0;
    				else if (h >= k) dp[l][r][m] = 1;
    				else {
    					dp[l][r][m] = (!dp[l + 1][r][h] || !dp[l][r - 1][h]);
    				}
    			}
    		}
    	}
    	
    	if (dp[1][n][0] == 0) cout << "NO" << endl;
    	else cout << "YES" << endl;
    }
    return 0;
}
