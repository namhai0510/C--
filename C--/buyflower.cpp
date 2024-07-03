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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31; 


ll n, m, ps[maxn + 2], res = 0;
pair<ll, ll> s[maxn + 2];

bool cmp(pair<ll, ll> A, pair<ll, ll> B){
	return A.fi > B.fi;
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) {
    	cin >> s[i].fi >> s[i].se;
    }
    sort(s + 1, s + 1 + m, cmp);
    
    ps[0] = 0;
    for (int i = 1; i <= m; ++i) ps[i] = ps[i - 1] + s[i].fi;
    
    res = ps[min(m, n)];
	for (int i = 1; i <= m; ++i) {
		ll l = 1, r = m, mid, k = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (s[mid].fi >= s[i].se) k = mid, l = mid + 1;
            else r = mid - 1;
        }
        
        if (k < i){
            k = min(k, n - 1);
            res = max(res, ps[k] + s[i].fi + (n - k - 1) * s[i].se);
        }
        else if (k <= n) res = max (res, ps[k] + (n - k) * s[i].se);
	}
	cout << res;

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
