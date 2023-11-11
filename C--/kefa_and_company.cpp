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

int Bs1 (ll x, int pre) {
    int l, r, mid;
    l = 1; r= n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid].fi >= x) r = mid - 1;
        else l = mid + 1;
    }
    
    return r;
}


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
    
    for (int i = 1; i <= n; ++i) {
    	int it = Bs1(a[i].fi + d, i);
    	ans = max(ans, val[it] - val[i - 1]);
    }
    cout << ans;
    
    return 0;
}