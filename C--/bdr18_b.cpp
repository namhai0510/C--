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

ll n, k, a[maxn + 2], s[maxn + 2];
ll ps[maxn + 2], res = 0, minval, maxval;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], ps[i] = ps[i - 1] + a[i];
    
    for (int i = 1; i + k - 1 <= n; ++i) s[i] = ps[i + k - 1] - ps[i - 1];
    
    minval = maxval = s[1];
    for (int i = k + 1; i + k - 1 <= n; ++i) {
    	res = max({res, abs(s[i] - minval), abs(s[i] - maxval)});
    	
    	minval = min(minval, s[i - k + 1]);
    	maxval = max(maxval, s[i - k + 1]);
    }
    
    cout << res << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r18_b
