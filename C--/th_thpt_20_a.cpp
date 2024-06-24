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

ull x, y;

vector<ll> primes;
bool P[maxn + 2];

void Sieve() {
	memset(P, 1, sizeof(P));
    P[0] = P[1] = 0;
    
    for (int i = 2; i * i <= maxn; ++i)
		if (P[i])
        	for (int j = i * i; j <= maxn; j += i) P[j] = 0;
	for (int i = 2; i <= maxn; ++i) if (P[i]) primes.pb(i);
}

ll cntDiv(ll n) {
    if (n == 1) return 1;
    
    ll cnt;
    vector<ll> powV;
    for (auto p : primes) {
        cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        if (cnt) powV.pb(cnt);
    }
    
    if (cnt) powV.pb(cnt);
    if (n != 1) powV.pb(1);
    
    ll ret = 1;
    for (auto i : powV) ret *= (i + 1);
    return ret;
}


ll GCD(ll a, ll b) {
	if (a < b) return GCD(b, a);
	
    if (b == 0) return a;
    return GCD(b, a % b);
}
int main() {
    nothing
    if (fopen("cau1.inp", "r")) {
        freopen("cau1.inp", "r", stdin);
        freopen("cau1.out", "w", stdout);
    }
    Sieve();
    cin >> x >> y;
    
    // cout << GCD(x, y) << endl;
    cout << cntDiv(GCD(x, y)) << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/th_thpt_20_a
