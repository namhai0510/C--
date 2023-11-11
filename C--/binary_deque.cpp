#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, s, a[maxn + 2], psum[maxn + 2], ans = +oo;

int Bs2 (ll x, int pre) {
	// lon nhat be hon bang
	ll l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (psum[mid] - psum[pre - 1] > x) r = mid - 1;
		else l = mid + 1;
	}
	
	return r;
}

int main() {
    nothing
    if (fopen("binary_deque.inp", "r")) {
        freopen("binary_deque.inp", "r", stdin);
        freopen("binary_deque.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> s;
    	ans = n + 1;
    	
    	psum[0] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		psum[i] = psum[i - 1] + a[i];
    	}
    	
    	if (psum[n] >= s) {
    		for (int i = 1; i <= n; ++i) {
	    		int it;
				it = Bs2(s, i);
				ans = min(ans, n - (it - i + 1));
	    		// cout << it << endl;
	    	}
    	}
    	
    	cout << (ans == n + 1 ? -1 : ans) << "\n";
    }
    return 0;
}

