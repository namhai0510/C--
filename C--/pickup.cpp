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
const int maxa = 5e3 + 5;
const int base = 31;

ll m, n, a[maxn + 2], f[maxa + 2][maxa + 2], ret = +oo;
ll ps[maxn + 2];
int main() {
    nothing
    if (fopen("pickup.inp", "r")) {
        freopen("pickup.inp", "r", stdin);
        freopen("pickup.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i];
    
    for (int i = 0; i <= n; ++i)
    	for (int j = 0; j <= m; ++j) f[i][j] = +oo;
    
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) 
    	for (int j = 1; j <= i; ++j) 
    		for (int k = j - 1; k < i; ++k)
    			f[i][j] = min(f[i][j], f[k][j - 1] - (ps[i] - ps[k]) + (i - k) * a[i]);
    
    cout << f[n][m] << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
