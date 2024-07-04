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

ll n, k, a[maxn + 2], f[maxn + 2];
ll ans = -oo;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	f[i] = f[i - 1] + a[i];
    	
    	for (int j = 2; j <= k; ++j) {
    		if (i - j < 0) break;
    		
    		f[i] = max(f[i], f[i - j] + a[i]);
    	}
    	
    	ans = max(ans, f[i]);
    }
    
    cout << ans << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
