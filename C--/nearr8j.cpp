#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, a[maxn + 2], pos = 1;
ll l, r, u, d;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    memset(a, 0, sizeof(a));
    cin >> m >> n;
    
    u = 1; d = m; l = 1; r = n;
    while (pos <= m * n) {
    	for (int i = l; i <= r; ++i) 
    		a[(u - 1) * n + i] = pos++;
    		
    	for (int j = d; j > u; --j)
    		a[(j - 1) * n + r] = pos++;
                
        r--; u++;
    }
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) cout << a[(i - 1) * n + j] << " ";
    	cout << "\n";
    }
    return 0;
}
