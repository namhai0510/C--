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

ll t, c[4][maxn + 2], n;
string s;

ll Bs2(ll x, int type, int pre) {
	int l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (c[type][mid] - c[type][pre - 1] >= x) r = mid - 1;
		else l = mid + 1;
	}
	
	return l;
}

int main() {
    nothing
    if (fopen("ternary_string.inp", "r")) {
        freopen("ternary_string.inp", "r", stdin);
        freopen("ternary_string.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> s;
    	s = '#' + s;
    	n = s.size() - 1;
    	c[1][0] = 0; c[2][0] = 0; c[3][0] = 0;
    	
    	for (int i = 1; i < s.size(); ++i) {
    		for (int j = 1; j <= 3; ++j) c[j][i] = c[j][i - 1];
    		
    		c[s[i] - '0'][i]++;
    	}
    	c[1][n + 1] = -1; c[2][n + 1] = -1; c[3][n + 1] = -1;
    	
    	ll ans = +oo;
    	for (int i = 1; i < s.size(); ++i) {
    		ll i1 = Bs2(1, 1, i), i2 = Bs2(1, 2, i), i3 = Bs2(1, 3, i);
    		
    		if (c[1][i1] - c[1][i - 1] >= 1 
    		&& c[2][i2] - c[2][i - 1] >= 1
    		&& c[3][i3] - c[3][i - 1] >= 1) {
    			ans = min(ans, max({i1, i2, i3}) - i + 1);
    		}
    			
    	}
    	
    	if (ans == +oo) cout << 0 << endl;
    	else cout << ans << endl;
    }
    
    return 0;
}