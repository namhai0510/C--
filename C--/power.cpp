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

ll n, k, a[maxn + 2];

ll prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
ll factor[maxn + 2];
ll ans = 1;

ll mult (ll a, ll b, ll mod) {
	if (b == 0) return 0;
	
	ll t = mult(a, b / 2, mod);
	t = (t + t) % mod;
	
	if (b % 2 == 1) t = (t + a) % mod;
	
	return t;
}

ll POW (ll a, ll b, ll mod) {
	if (b == 0) return 1;
	
    ll t = POW(a, b / 2, mod);         
    t = (t * t) % mod; 
    
    if (b % 2 == 1) t = (t * a) % mod;
    
    return t;
}
int main() {
    nothing
    if (fopen("power.inp", "r")) {
        freopen("power.inp", "r", stdin);
        freopen("power.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= 13; ++j) {
    		ll cnt = 0;
    		
    		while (a[i] % prime[j] == 0) {
    			cnt++;
    			a[i] /= prime[j];
    		}
    		
    		factor[prime[j]] = max(factor[prime[j]], cnt);
    	}
    }
    
    for (int i = 1; i <= 13; ++i) {
    	ll exp = factor[prime[i]] / k;
    	if (factor[prime[i]] % k != 0) exp++;
    	
    	ans *= POW(prime[i], exp, modd);
    }
    
    cout << ans << endl;
    
    return 0;
}
