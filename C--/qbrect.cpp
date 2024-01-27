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

ll m, n, a[maxa + 2][maxa + 2], res = 0;
ll h[maxn + 2], r[maxn + 2], l[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    h[0] = h[n + 1] = -1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            h[j] = a[i][j] * (h[j] + 1);
            
        for (int j = 1; j <= n; ++j) {
            l[j] = j;
            while (h[l[j] - 1] >= h[j]) l[j] = l[l[j] - 1];
        }
        
        for (int j = n; j >= 1; --j) {
            r[j] = j;
            while (h[r[j] + 1] >= h[j]) r[j] = r[r[j] + 1];
        }
        for (int j = 1;j <= n; ++j)
            res = max(res, h[j] * (r[j] - l[j] + 1)); 
    }
    
    cout << res << endl;
    return 0;
}
