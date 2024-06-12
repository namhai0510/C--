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

ll n, m;
ll BIT[3][maxn + 2];

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

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
	Construct();
    
    for (int i = 1; i <= m; ++i) {
    	ll type;
    	cin >> type;
    	
    	if (type == 1) {
    		ll l, r, val;
    		cin >> l >> r >> val;
    		UpdateRange(l, r, val);
    	}
    	else {
    		ll x;
    		cin >> x;
    		cout << PrefixSum(x) - PrefixSum(x - 1) << endl;
    	}
    }
    
    // for (int i = 1; i <= n; ++i) cout << PrefixSum(i) << " ";
    return 0;
}
