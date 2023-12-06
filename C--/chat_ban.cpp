#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e17 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, k, x;

ll Calc(ll pos) {
	ll res = 0;
	if (pos > k) {
		pos = 2 * k - pos - 1;
		res = k * k - pos * (pos + 1) / 2;
	}
	else res = pos * (pos + 1) / 2;
	
	return res;
}

ll Bs (ll val) {
	ll l = 1, r = 2 * k + 1, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Calc(mid) >= val) {
			// so luong lon hon bang
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	return l;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> k >> x;
    	
    	if (k * k <= x) cout << 2 * k - 1 << endl;
    	else cout << Bs(x) << endl;
    }
    return 0;
}