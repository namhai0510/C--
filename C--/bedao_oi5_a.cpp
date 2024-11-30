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

ll n;
ll a[maxn + 2], l[maxn + 2], r[maxn + 2], range[maxn + 2], res;

ll st[4 * maxn + 4], lazy[4 * maxn + 4];

ll Pow(ll a, ll b) {
    ll res = 1;
    
    for(; b > 0; b >>= 1, a = a * a % mod)
        if(b & 1)
            res = res * a % mod;
    
    return res;
}

void Down(int id) {
    ll &x = lazy[id];
    
    st[id << 1] = st[id << 1] * x % mod;
    st[id << 1 | 1] = st[id << 1 | 1] * x % mod;
    lazy[id << 1] = lazy[id << 1] * x % mod;
    lazy[id << 1 | 1] = lazy[id << 1 | 1] * x % mod;
    
    x = 1;
}

void Update(int id, int l, int r, int tl, int tr, ll val) {
    if (l > tr || tl > r) return;
    
    if (tl <= l && r <= tr) {
        st[id] = st[id] * val % mod;
        lazy[id] = lazy[id] * val % mod;
        return;
    }
    
    int mid = (l + r) >> 1;
    Down(id);
    
    Update(id << 1, l, mid, tl, tr, val);
    Update(id << 1 | 1, mid + 1, r, tl, tr, val);
    
    st[id] = st[id << 1] * st[id << 1 | 1] % mod;
}

ll Get(int id, int l, int r, int pos) {
    if (l == r) return st[id];
    
    int mid = (l + r) >> 1;
    Down(id);
    
    if (pos <= mid)
        return Get(id << 1, l, mid, pos);
        
    return Get(id << 1 | 1, mid + 1, r, pos);
}

int main() {
    nothing
    if (fopen("oneshot.inp", "r")) {
        freopen("oneshot.inp", "r", stdin);
        freopen("oneshot.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
    	cin >> l[i] >> r[i];
    	
    	if (l[i] <= r[i]) range[i] = r[i] - l[i] + 1;
        else range[i] = (n - l[i] + 1) + r[i];
    }
    
    for (int i = 0; i < 4 * maxn; ++i)
        st[i] = lazy[i] = 1;

    for (int i = 1; i <= n; ++i){
        ll x = (range[i] - 1) * Pow(range[i], mod - 2) % mod;
        if (l[i] <= r[i]) {
            Update(1, 1, n, l[i], r[i], x);
        }
        else {
            Update(1, 1, n, l[i], n, x);
            Update(1, 1, n, 1, r[i], x);
        }
    }

    res = 0;
    for (int i = 1; i <= n; ++i) {
        ll p = Get(1, 1, n, i);
        
        res += (a[i] - (2 * a[i] * p % mod) + mod) % mod;
        res %= mod;
    }

    cout << res;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
