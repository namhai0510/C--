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

ll l, r;
ll n, s = 1;
ll k[150];

void Sub1() {
	ll dp[maxn + 2], d[maxn + 2], c[maxn + 2];
	
	c[0]=1;
    for (int i = 1;i <= r; ++i) {
        dp[i] = c[i - 1];
        d[i] = (d[i - 1] + dp[i]) % mod;
        c[i] = (c[i - 1] + d[i]) % mod;
    }
    
    cout << (c[r] - c[l - 1] + mod) % mod << endl;
}

void Sub2() {
	ll dp[maxn + 2], d[2][125], c[2][125];
	
	memset(dp, 0, sizeof(dp));
    memset(d, 0, sizeof(d));
    memset(c, 0, sizeof(c));
    
    vector<ll> v;
    
    for (int i = 1; i <= n; ++i) 
    	for (int j = k[i]; j <= 121; j += k[i]) v.push_back(j);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    c[0][0]=d[0][0]=1;
    ll res = 0;
    for (int i = 1; i <= r; ++i) {
        ll t = (i & 1);
        dp[t] = 0;
        
        for (int u : v) (dp[t] += c[t ^ 1][u - 1]) %= mod;
        
        d[t][0]=(d[t ^ 1][s - 1] + dp[t]) % mod;
        c[t][0]=(c[t ^ 1][s - 1] + d[t][0]) % mod;
        for (int k = 1; k < s; ++k) {
            d[t][k]=d[t ^ 1][k - 1];
            c[t][k]=(c[t ^ 1][k - 1] + d[t][k]) % mod;
        }
        
        if (i >= l) (res += dp[t]) %= mod;
    }
    
    cout << res << endl;
}

void Sub3() {
	
}

void Sub4() {
	
}

int main() {
    nothing
    if (fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    
    cin >> l >> r >> n;
    s = 1;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        s = s / __gcd(s, k[i]) * k[i];
    }

    if (s == 1 && r <= 1000000) Sub1();
    else if (r <= 1000000) Sub2();
    else if (s == 1) Sub3();
    else Sub4();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
