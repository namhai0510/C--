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

ll n, a[maxn + 2], ps[maxn + 2];
ll m, u, v;

ll pow(ll a, ll n, ll m) {
    ll result = 1;
    a = a % m;
    while (n > 0) {
        if (n & 1) result = result * a % m;
        n >>= 1;
        a = a * a % m;
    }
    return result;
}

pair<ll, ll> factor(ll n) {
    ll s = 0;
    while ((n & 1) == 0) {
        s++;
        n >>= 1;
    }
    return {s, n};
}

bool witness_test(ll s, ll d, ll n, ll witness) {
    if (n == witness) return true;
    ll p = pow(witness, d, n);
    if (p == 1) return true;
    for (; s > 0; s--) {
        if (p == n-1) return true;
        p = p * p % n;
    }
    return false;
}

bool miller(ll n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    ll s, d;
    tie(s, d) = factor(n-1);
    return witness_test(s, d, n, 2) && witness_test(s, d, n, 7) && witness_test(s, d, n, 61);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	ps[i] = ps[i - 1] + a[i];
    }
    
    
    for (int test = 1; test <= m; ++test) {
    	cin >> u >> v;
    	
    	ll tmp = ps[v] - ps[u - 1];
    	
    	cout << miller(tmp) << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hp_thpt_23_c
