#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll unsigned long long
// #define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e15 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, x, a[maxn + 2], ps[maxn + 2];

ll Bs3 (ll x) {
    ll l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        
        if (a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    
    return r;
}

ll Calc(ll h) {
	ll it = Bs3(h);
	return (h * it - ps[it]);
}

ll Bs(ll val) {
	ll l = 1, r = +oo, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Calc(mid) <= val) l = mid + 1;
		else r = mid - 1;
	}
	
	return r;
}

int main() {
    nothing
    if (fopen("building_an_aquarium.inp", "r")) {
        freopen("building_an_aquarium.inp", "r", stdin);
        freopen("building_an_aquarium.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> x;
    	ps[0] = 0;
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	sort(a + 1, a + 1 + n);
    	
    	for (int i = 1; i <= n; ++i) {
    		ps[i] = ps[i - 1] + a[i];
    	}
    	
    	cout << Bs(x) << endl;
    }
    return 0;
}