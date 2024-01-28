#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll n, q;
ll st[4 * maxn];
pair<ll, ll> lazy[4 * maxn];

void fix(ll id, ll l, ll r) {
    ll a = lazy[id].fi, b = lazy[id].se;
    
    st[id] += (a * (r + l) * (r - l + 1) / 2) % modd;
    st[id] += (b * (r - l + 1)) % modd;
    st[id] %= modd;
    
    if (l != r){
        lazy[2 * id].fi = (lazy[2 * id].fi + a) % modd;
        lazy[2 * id].se = (lazy[2 * id].se + b) % modd;
        lazy[2 * id + 1].fi = (lazy[2 * id + 1].fi + a) % modd;
        lazy[2 * id + 1].se = (lazy[2 * id + 1].se + b) % modd;
    }
    
    lazy[id] = {0, 0};
}

void update(ll id, ll l, ll r, ll u, ll v, ll a, ll b) {
    fix(id, l, r);
    if (l >  v || r < u) return;
    if (l >= u && r <= v) {
        lazy[id].fi = a;
        lazy[id].se = (b - u * a + modd * modd) % modd;
        fix(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, a, b);
    update(2 * id + 1, mid + 1, r, u, v, a, b);
    st[id] = (st[2 * id] + st[2 * id + 1]) % modd;
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    fix(id, l, r);
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];

    ll mid  = (l + r) >> 1;
    ll get1 = get(2 * id, l, mid, u, v);
    ll get2 = get(2 * id + 1, mid + 1, r, u, v);
    return (get1 + get2) % modd;
}

int main() {
    if (fopen("ss.inp","r")) {
        freopen("ss.inp","r",stdin);
        freopen("ss.out","w",stdout);
    }
    nothing;
    cin >> n >> q;
    while (q--) {
    	int type; cin >> type;
    	if (type == 1) {
    		ll l, r, a, b;
    		cin >> l >> r >> a >> b;
			update(1, 1, n, l, r, a, b);
    	}
    	else {
    		ll l, r;
    		cin >> l >> r;
    		cout << get(1, 1, n, l, r) << endl;
    	}
    }
    return 0;
}
