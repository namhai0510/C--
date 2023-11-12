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

ll n, d, val[maxn + 2], ans = -1;
pair<ll, ll> a[maxn + 2];

int main() {
    nothing
    if (fopen("kefa_and_company.inp", "r")) {
        freopen("kefa_and_company.inp", "r", stdin);
        freopen("kefa_and_company.out", "w", stdout);
    }
    cin >> n >> d;
    
    for (int i = 1; i <= n ; ++i) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	val[i] = val[i - 1] + a[i].se;
    }
    val[n + 1] = +oo;
    
    // for (int i = 1; i <= n; ++i) cout << a[i].fi << " " << a[i].se << endl;
    
    ll l = 1, r = 1;
    while (r <= n) {
    	if (a[r].fi - a[l].fi < d) {
    		ans = max(ans, val[r] - val[l - 1]);
    		r++;
    	}
    	else {
    		l++;
    	}
    }
    cout << ans;
    
    return 0;
}