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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, k, l, r, mid, res, cnt;
ll dif[maxn + 2];
pair<ll, ll> a[maxn + 2];

bool Check(ll val) {
	cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += (a[i].se - a[i].fi) / val;
	
	return (cnt >= k);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].fi >> a[i].se;
    	dif[i] = a[i].se - a[i].fi;
    }
    
    r = dif[1];
    for (int i = 2; i <= n; ++i) r = max(r, dif[i]);
    
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	if (Check(mid)) {
    		l = mid + 1;
    		res = mid;
    	}
    	else r = mid - 1;
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
