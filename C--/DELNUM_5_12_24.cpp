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

ll n, cnt = 0;
ll a[maxn + 2];
ll prime[maxn + 2], dp[maxn + 2];

void Sieve() {
	for (int i = 1; i <= maxn; ++i) prime[i] = i;
	
	for (int i = 2; i * i <= maxn; ++i) {
		if (prime[i] == i) {
			for (int j = i * i; j <= maxn; j += i) 
				if (prime[j] == j) prime[j] = i;
		}
	}
}

void Reset(ll x, ll val) {
    while (x > 1) {
        ll t = prime[x]; 
        while(x % t == 0) {
            x /= t;  
        }
        
        dp[t] = max(dp[t], val); 
    }
}

int main() {
    nothing
    if (fopen("DELNUM.inp", "r")) {
        freopen("DELNUM.inp", "r", stdin);
        freopen("DELNUM.out", "w", stdout);
    }
    Sieve();
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
        ll x = a[i] ; 
        ll val = 0; 
        while (x > 1) {
            ll t = prime[x]; 
            while (x % t ==0) {
                x /= t;
            }
            val = max(val, dp[t] + 1); 
        }
        cnt = max(cnt, val); 
        Reset(a[i], val); 
    }
    
    cout << n - cnt; 
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
