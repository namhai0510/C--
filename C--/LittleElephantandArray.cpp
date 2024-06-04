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
const int base = 31;

ll n, m, a[maxn + 2];
ll f[maxn + 2], p[maxn + 2], l[maxn + 2], r[maxn + 2], ans[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	if (a[i] <= n) f[a[i]]++;
    }
    
    for (int i = 1; i <= m; ++i) {
    	cin >> l[i] >> r[i];
    	
    	ans[i] = 0;
    }
    p[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
    	if (f[i] >= i) {
    		for (int j = 1; j <= n; ++j)  {
    			p[j] = p[j - 1];
    			if (a[j] == i) p[j]++;
    		}
    		
    		for (int j = 1; j <= m; ++j) {
    			if (p[r[j]] - p[l[j] - 1] == i) ans[j]++;
    		}
    	}
    }
    
    for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/220/B