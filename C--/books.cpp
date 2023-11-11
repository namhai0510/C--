#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, t, a[maxn + 2], psum[maxn + 2], ans = 0;

int Bs3 (ll x, int pre) {
	int l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (psum[mid] - psum[pre - 1] > x) r = mid - 1;
		else l = mid + 1;
	}
	
	return r;
}

int main() {
    nothing
    if (fopen("books.inp", "r")) {
        freopen("books.inp", "r", stdin);
        freopen("books.out", "w", stdout);
    }
    cin >> n >> t;
    
    psum[0] = 0; psum[n + 1] = +oo;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
    	ll leng  = (Bs3(t, i) <= n ? Bs3(t, i) - i + 1 : 0);
    	ans = max(ans, leng);
    	// cout << i << " " << Bs3(t, i) << " " << leng << endl;
    }
    cout << ans << endl;
    
    return 0;
}