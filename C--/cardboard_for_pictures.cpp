#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ull oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ull t, n, c, a[maxn + 2];

ull Calc (ll x) {
	ull ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (a[i] + 2 * x) * (a[i] + 2 * x);
		if (ans > c) return -1;
	}
	return ans;
}

ull Bs (ll val) {
	ull l = 1, r = +oo, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Calc(mid) != -1 && Calc(mid) <= val) l = mid + 1;
		else r = mid - 1;
	}
	
	return r;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n >> c;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	// sort(a + 1, a + 1 + n);
    	
    	cout << Bs(c) << endl;
    }
    return 0;
}

