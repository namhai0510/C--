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
const ll mod = 998244353;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, k;
ll fct[maxn + 2], res = 0;

ll Add(ll x, ll y) {
	x += y;
	
	while (x >= mod) x -= mod;
	while (x < 0) x += mod;
	
	return x;
}

ll BinPow(ll x, ll y) {
	ll z = 1;
	while(y > 0) {
		if (y % 2 == 1) z = (x * z) % mod;
		
		x = (x * x) % mod;
		y /= 2;
	}
	return z;
}

ll Div(ll x, ll y) {
	return x * BinPow(y, mod - 2) % mod;
}

void Init() {
	fct[0] = 1;
	for (int i = 1; i <= maxn; ++i)
		fct[i] = i * 1LL * fct[i - 1] % mod;
}

ll C(ll n, ll k) {
	if(k > n) return 0;
	
	return Div(fct[n], (fct[n - k] * fct[k]) % mod);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	Init();
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		ll d = n / i;
		
		res = Add(res, C(d - 1, k - 1));
	}
	    
	cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1359/E
