#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

struct Data {
	ll p, t;
};

ll n, x;
Data a[maxn + 2];

bool cmp(Data A, Data B) {
	return A.p < B.p;
}

ll CountEggs(ll t) {
	ll ret = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i].p > t) return ret;
		
		ret += 1 + round((t - a[i].p) / a[i].t);
	}
	
	return ret;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> x;
    
    for (int i = 1; i <= n; ++i) cin >> a[i].p >> a[i].t;
    sort(a + 1, a + 1 + n, cmp);
    
    ll l = 0, r = +oo, mid;
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	if (CountEggs(mid) >= x) r = mid - 1;
    	else l = mid + 1;
    }
    
    cout << l << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hp_thpt_22_c