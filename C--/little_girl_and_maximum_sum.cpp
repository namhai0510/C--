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

ll n, q, a[maxn + 2], l[maxn + 2], r[maxn + 2], d[maxn + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> q;
    
    memset(d, 0, sizeof(d));
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    for (int i = 1; i <= q; ++i) {
    	cin >> l[i] >> r[i];
    	
    	d[l[i]]++;
    	d[r[i] + 1]--;
    }
    
    for  (int i = 1; i <= n; ++i) {
    	d[i] += d[i - 1];
    }
    
    sort(d + 1, d + 1 + n);
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	ans += a[i] * d[i];
    }
    
    // for (int i = 1; i <= n; ++i) {
    	// cout << d[i] << " ";
    // }
    // cout << endl;
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/276/C