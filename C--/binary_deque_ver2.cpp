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
    	// chon doan giua dai nhat co tong == s
    	cin >> n >> s;
    	ans = n + 1;
    	
    	psum[0] = 0; psum[n + 1] = +oo;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		psum[i] = psum[i - 1] + a[i];
    	}
    	
    	ll l = 1, r = 1;
    	if (psum[n] >= s) {
    		while (r <= n) {
    			if (psum[r] - psum[l - 1] == s) {
    				ans = min(ans, n - (r - l + 1));
    				// cout << l << " " << r << " " << (r - l + 1) << endl;
    				r++;
    			}
    			else if (psum[r] - psum[l - 1] < s) {
    				r++;
    			}
    			else if (psum[r] - psum[l - 1] > s) {
    				l++;
    			}
    		}
    	}
    	cout << (ans == n + 1 ? -1 : ans) << "\n";
    }
    return 0;
}

