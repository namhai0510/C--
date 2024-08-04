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

ll n, ans = 0;
ll a[450][450];
ll c1, c2;

int main() {
    nothing
    if (fopen("colorec.inp", "r")) {
        freopen("colorec.inp", "r", stdin);
        freopen("colorec.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	ll x, y, c;
    	cin >> x >> y >> c;
    	a[x + 200][y + 200] = c;
    }
    
    for (int i = 0; i <= 2 * 200; ++i) {
    	for (int j = i + 1; j <= 2 * 200; ++j) {
    		c1 = c2 = 0;
    		for (int k = 0; k <= 2 * 200; ++k) {
    			if ((a[i][k] == 1 && a[j][k] == 4) || (a[i][k] == 4 && a[j][k] == 1)) 
    				c1++;
    			if ((a[i][k] == 2 && a[j][k] == 3) || (a[i][k] == 3 && a[j][k] == 2))
    				c2++;
    		}
    		
    		ans += c1 * c2;
    		
    		c1 = c2 = 0;
    		for (int k = 0; k <= 2 * 200; ++k) {
	    		if ((a[i][k] == 1 && a[j][k] == 3) || (a[i][k] == 3 && a[j][k] == 1)) 
	    			c1++;
    			if ((a[i][k] == 2 && a[j][k] == 4) || (a[i][k] == 4 && a[j][k] == 2))
    				c2++;
    		}
    		
    		ans += c1 * c2;
    		
    		c1 = c2 = 0;
    		for (int k = 0; k <= 2 * 200; ++k) {
	    		if ((a[i][k] == 1 && a[j][k] == 2) || (a[i][k] == 2 && a[j][k] == 1)) 
	    			c1++;
    			if ((a[i][k] == 3 && a[j][k] == 4) || (a[i][k] == 4 && a[j][k] == 3))
    				c2++;
    		}
    		
    		ans += c1 * c2;
    	}
    }
    
    cout << ans << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
