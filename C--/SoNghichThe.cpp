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

ll n, b[maxn + 2];
ll BIT[3][maxn + 2];
pair<ll, ll> a[maxn + 2];

void Update(ll pos, ll val, int type) {
	while (pos <= n) {
		BIT[type][pos] += val; 
		// type 1 : update a[pos] += val
		// type 2 & 3 : update a[l...r] += val
		pos += pos & (-pos);
	}
}

void UpdateRange(ll l, ll r, ll val) {
	Update(l, (n - l + 1) * val, 1);
	Update(r + 1, -(n - r) * val, 1);
    Update(l, val, 2);
    Update(r + 1, -val, 2);
}

void Construct() {
	for (int i = 1; i <= n; ++i) BIT[0][i] = BIT[1][i] = BIT[2][i] = 0;
}

ll Get(ll pos, int type) {
	ll ret = 0;
	
	while (pos >= 1) {
		ret += BIT[type][pos];
		pos -= pos & (-pos);
	}
	
	return ret;
}

ll PrefixSum(ll pos) {
	return Get(pos, 1) - Get(pos, 2) * (n - pos);
}

ll res = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
	Construct();
    
    for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
    sort(a + 1, a + 1 + n);
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++) {
		if (a[i].first != a[i - 1].first) b[a[i].second] = ++cnt;
		else b[a[i].second] = cnt;
	}
    
    for (int i = n; i >= 1; --i) {
    	res += Get(b[i] - 1LL, 0);
    	Update(b[i], 1, 0);
    }
    
    cout << res << endl;
    return 0;
}
