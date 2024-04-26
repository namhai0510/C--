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

ll n, m, p, ans = +oo;
ll a[maxn + 2], b[maxn + 2], c[maxn + 2];

int main() {
    nothing
    if (fopen("lightball.inp", "r")) {
        freopen("lightball.inp", "r", stdin);
        freopen("lightball.out", "w", stdout);
    }
    cin >> n >> m >> p;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int j = 1; j <= m; ++j) {
    	cin >> b[j];
    }
    sort(b + 1, b + 1 + m);
    for (int k = 1; k <= p; ++k) {
    	cin >> c[k];
    }
    sort(c + 1, c + 1 + p);
    
    a[n + 1] = b[m + 1] = c[p + 1] = +oo;
    
    for (int i = 1; i <= n; ++i) {
    	ll x, y, z;
    	
    	int j = lower_bound(b + 1, b + 1 + m, a[i]) - b;
    	int k = lower_bound(c + 1, c + 1 + p, a[i]) - c;
    	
    	if (j <= m && k <= p) {
    		x = (a[i] - b[j]);
    		y = (b[j] - c[k]);
    		z = (c[k] - a[i]);
    		
    		x = x * x;
    		y = y * y;
    		z = z * z;
    		
    		ans = min(ans, x + y + z);
    	}
    }
    
    for (int j = 1; j <= m; ++j) {
    	ll x, y, z;
    	
    	int i = lower_bound(a + 1, a + 1 + n, b[j]) - a;
    	int k = lower_bound(c + 1, c + 1 + p, b[j]) - c;
    	
    	if (i <= n && k <= p) {
    		x = (a[i] - b[j]);
    		y = (b[j] - c[k]);
    		z = (c[k] - a[i]);
    		
    		x = x * x;
    		y = y * y;
    		z = z * z;
    		
    		ans = min(ans, x + y + z);
    	}
    }
    
    for (int k = 1; k <= p; ++k) {
    	ll x, y, z;
    	
    	int i = lower_bound(a + 1, a + 1 + n, c[k]) - a;
    	int j = lower_bound(b + 1, b + 1 + m, c[k]) - b;
    	
    	if (i <= n && j <= m) {
    		x = (a[i] - b[j]);
    		y = (b[j] - c[k]);
    		z = (c[k] - a[i]);
    		
    		x = x * x;
    		y = y * y;
    		z = z * z;
    		
    		ans = min(ans, x + y + z);
    	}
    }
    
    cout << ans << endl;
    return 0;
}
