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
ll BIT[maxn + 2];

void Update(ll pos, ll val) {
	while (pos <= n) {
		BIT[pos] += val;
		pos += pos & (-pos);
	}
}

void Construct() {
	for (int i = 1; i <= n; ++i) BIT[i] = 0;
}

ll Get(ll pos) {
	ll ret = 0;
	
	while (pos >= 1) {
		ret += BIT[pos];
		pos -= pos & (-pos);
	}
	
	return ret;
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
    		ll x, d;
    		cin >> x >> d;
    		Update(x, d);
    	}
    	else {
    		ll l, r;
    		cin >> l >> r;
    		cout << Get(r) - Get(l - 1) << endl;
    	}
    }
    return 0;
}
