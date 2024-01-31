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

struct Data {
	ll add, mul;
};

ll n, q;
ll a[maxn], st[4 * maxn + 2];
Data lazy[4 * maxn + 2];

void PreCal() {
	for (int i = 1; i <= 4 * maxn; ++i) {
		st[i] = 0;
		lazy[i].add = 0;
		lazy[i].mul = 1;
	}
}

void Build(int l, int r, int id) {
	if (l == r) {
		st[id] = a[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	Build(l, mid, 2 * id);
	Build(mid + 1, r, 2 * id + 1);
	
	st[id] = st[2 * id] + st[2 * id + 1];
	st[id] %= modd;
}


void Fix(int l, int r, int id) {
	if (lazy[id].add == 0 && lazy[id].mul == 1) return;
	
	st[id] = (lazy[id].mul * st[id]) % modd;
	st[id] = (lazy[id].add * (r - l + 1) + st[id]) % modd;
	
	if (l != r) {
		lazy[2 * id].mul = lazy[id].mul * lazy[2 * id].mul % modd;
		lazy[2 * id + 1].mul = lazy[id].mul * lazy[2 * id + 1].mul % modd;
		
		lazy[2 * id].add = (lazy[id].mul * lazy[2 * id].add % modd + lazy[id].add) % modd;
		lazy[2 * id + 1].add = (lazy[id].mul * lazy[2 * id + 1].add % modd + lazy[id].add) % modd;
	}
	
	lazy[id].add = 0;
	lazy[id].mul = 1;
}

void Update(int l, int r, int id, int u, int v, int type, ll val) {
	Fix(l, r, id);
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		if (type == 1) {
			lazy[id].add = (val + lazy[id].add) % modd;
		}
		else if (type == 2) {
			lazy[id].mul = (val * lazy[id].mul) % modd;
			lazy[id].add = (val * lazy[id].add) % modd;
		}
		else if (type == 3) {
			lazy[id].mul = 0;
			lazy[id].add = val;
		}
		Fix(l, r, id);
		return;
	}
	
	int mid = (l + r) >> 1;
	Update(l, mid, 2 * id, u, v, type, val);
	Update(mid + 1, r, 2 * id + 1, u, v, type, val);
	
	st[id] = st[2 * id] + st[2 * id + 1];
	st[id] %= modd;
}

int Get(int l, int r, int id, int u, int v) {
    Fix(l, r, id);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];

    int mid  = (l + r) >> 1;
    ll Get1 = Get(l, mid, 2 * id, u, v);
    ll Get2 = Get(mid + 1, r, 2 * id + 1, u, v);
    return (Get1 + Get2) % modd;
}

int main() {
	nothing;
    if (fopen("ss.inp","r")) {
        freopen("ss.inp","r",stdin);
        freopen("ss.out","w",stdout);
    }
    PreCal();
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    Build(1, n, 1);
    
    while (q--) {
    	int type, l, r;
    	cin >> type >> l >> r;
    	
    	if (type == 4) {
    		cout << Get(1, n, 1, l, r) << endl;
    	}
    	else {
    		ll x; cin >> x;
    		Update(1, n, 1, l, r, type, x);
    	}
    }
    
    return 0;
}


// https://oj.vnoi.info/problem/segtree_itmix