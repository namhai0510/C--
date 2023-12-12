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

ll t, n, h[maxn + 2], h2[maxn + 2], hmax = -oo, hmin = +oo;

bool Check(ll val) {
	for (int i = 1; i <= n; ++i) h2[i] = h[i];
	
	for (int i = n; i >= 1; --i) {
		if (h2[i] < val) return 0;
		
		ll d = min(h[i], h2[i] - val) / 3;
		if (i > 2) {
			h2[i - 1] += d;
			h2[i - 2] += d * 2;
		}
	}
	
	return 1;
}
 
ll Bs() {
	ll l = hmin, r = hmax, mid, ans;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("balanced_stone_heaps.inp", "r")) {
        freopen("balanced_stone_heaps.inp", "r", stdin);
        freopen("balanced_stone_heaps.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	hmin = +oo; hmax = -oo;
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> h[i];
    		hmin = min(hmin, h[i]);
    		hmax = max(hmax, h[i]);
    	}
    	
    	cout << Bs() << endl;
    	
    	// for (int i = 1; i <= n; ++i) cout << h2[i] << " ";
    	// cout << endl;
    }
    return 0;
}