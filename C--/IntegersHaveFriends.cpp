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

const int LG = 20;

ll test, n, a[maxn + 2];
ll D[maxn + 2][LG + 2], ans = 1;

ll Calc(ll l, ll r) {
	if (l > r) return 0;
	
	ll length = r - l + 1;
	ll m = 31 - __builtin_clz(length);
	
	return __gcd(D[l][m], D[r - (1 << m) + 1][m]);
	
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	for (int i = 1; i <= n - 1; ++i) D[i][0] = abs(a[i + 1] - a[i]);
    	for (int j = 1; j <= LG; ++j) {
    		for (int i = 1; i + (1 << j) <= n; ++i) {
    			D[i][j] = __gcd(D[i][j - 1], D[i + (1 << (j - 1))][j - 1]);
    		}
    	}
    	
    	ans = 1;
    	for (int i = 1; i <= n; ++i) {
    		ll le = i + 1, ri = n, tmp = i, mid, val;
    		
    		while (le <= ri) {
    			mid = (le + ri) / 2;
    			val = Calc(i, mid - 1);
    			
    			// cout << le << " " << ri << " " << mid << " " << val << endl;
    			
    			if (val == 1) ri = mid - 1;
    			else le = mid + 1, tmp = mid;
    		}
    		
    		ans = max(ans, tmp - i + 1);
    	}
    	
    	cout << ans << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1548/B
