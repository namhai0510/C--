#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ull oo = 1e19 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ull t, n, h, a[maxn + 2];

ull Calc(ll x) {
	ull res = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] + x - 1 < a[i + 1]) res += x;
		else res += a[i + 1] - a[i];
	}
	
	return res;
}

ull Bs(ll val) {
	ull l = 1, r = +oo, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (Calc(mid) >= val) r = mid - 1;
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
    	cin >> n >> h;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	a[n + 1] = +oo;
    	
    	cout << Bs(h) << endl;
    }
    return 0;
}