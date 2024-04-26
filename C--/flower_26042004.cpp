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

ll n, k, ans = +oo;

ll a[maxn], st[maxn * 4], dp[maxn], sum = 0;

void update(ll i, ll val, ll id = 1, ll l = 1, ll r = n){
	if (l > i or r < i) return;
	if (l == r){
		st[id] = val;
		return;
	}
	ll mid = l + r >> 1;
	update(i, val, id * 2, l, mid);
	update(i, val, id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

ll get(ll u, ll v, ll id = 1, ll l = 1, ll r = n){
	if (r < u or v < l) return +oo;
	if (u <= l and r <= v) return st[id];
	ll mid = l + r >> 1;
	ll x = get (u, v, id * 2, l, mid);
	ll y = get (u, v, id * 2 + 1, mid + 1, r);
	return min (x, y);
}

int main() {
    nothing
    if (fopen("flower.inp", "r")) {
        freopen("flower.inp", "r", stdin);
        freopen("flower.out", "w", stdout);
    }
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	sum += a[i];
    }
    
    for (int i = 1; i <= k; ++i) {
    	dp[i] = a[i];
    	update(i, dp[i]);
    }
    
    for (int i = k + 1; i <= n; ++i){
		dp[i] = get(i - k, i - 1) + a[i];
		update(i, dp[i]);
	}
	for (int i = n - k + 1; i <= n; i++){
		ans = min(ans, dp[i]);
	}
	
	cout << sum - ans << endl;
    return 0;
}
