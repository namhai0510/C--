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
const int maxa = 5e3;
const int base = 31;

ll n, t, q;
ll a[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> t;
    
    for (int i = 1; i <= t; ++i) {
    	int k, rc, x, y;
    	cin >> k >> rc >> x >> y;
    	
    	if (k == 1) {
    		for (int j = 1; j <= (y - x + 2) / 2; ++j) {
    			a[rc][x + j - 1] += j;
    			a[rc][y - j + 1] += j;
    			
    			if (x + j - 1 == y - j + 1) 
    				a[rc][x + j - 1] -= j;
    		}
    	}
    	else {
    		for (int j = 1; j <= (y - x + 2) / 2; ++j) {
    			a[x + j - 1][rc] += j;
    			a[y - j + 1][rc] += j;
    			
    			if (x + j - 1 == y - j + 1) 
    				a[x + j - 1][rc] -= j;
    		}
    	}
    	
    	// for (int u = 1; u <= n; ++u) {
    		// for (int v = 1; v <= n; ++v) cout << a[u][v] << " ";
//     		
    		// cout << endl;
    	// }
    	// cout << "------" << endl;
    }
    cin >> q;
    
    while (q--) {
    	int u, v;
    	
    	cin >> u >> v;
    	
    	cout << a[u][v] << endl;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
