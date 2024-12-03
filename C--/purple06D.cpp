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
const int maxa = 2e3;
const int base = 31;

ll m, n;
ll a[maxn + 2], b[maxn + 2];
ll pos = 1, candies[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    
    for (int i = 1; i <= m; ++i) {
    	if (pos + b[i] <= n) {
    		candies[pos] += a[i];
    		candies[pos + b[i]] -= a[i];
    		
    		pos = (pos + b[i] - 1) % n + 1;
    		continue;
    	}
    	
    	candies[pos] += a[i];
    	candies[n + 1] -= a[i];
    	
    	candies[1] += a[i];
    	candies[pos + b[i] - n] -= a[i];
    	
    	pos = pos + b[i] - n;
    }
    
    for (int i = 1; i <= n; ++i) {
    	candies[i] += candies[i - 1];
    	
    	cout << candies[i] << " ";
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
