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

ll n, k, a[maxa + 2][maxa + 2], ps[maxa + 2][maxa + 2];
ll ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    		ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + a[i][j];
    	}
    }
    
    
    for (int i = k; i <= n; ++i) {
    	for (int j = k; j <= n; ++j) {
    		ans = max(ans, ps[i][j] - ps[i - k][j] - ps[i][j - k] + ps[i - k][j - k]);
    	}
    }
    
    cout << ans << endl;
    
    return 0;
}

// https://oj.vnoi.info/problem/bonus

