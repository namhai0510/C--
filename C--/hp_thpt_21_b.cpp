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

ll n, t, a[maxn + 2], cnt[maxn + 2];

ll binaryPower(ll a, ll k, ll n) {
    a = a % n;
    
    ll res = 1;
    while (k) {
        if (k & 1) res = (res * a) % n;
        a = (a * a) % n;
        k /= 2;
    }
    
    return res;
}

bool CheckPrime(ll n) {
    if (n < 7) return n == 2 || n == 3 || n == 5;

    static const ll repeatNum = 5;
    for (int i = 0; i < repeatNum; ++i) {
        int a = rand() % (n - 3) + 2;
        if (binaryPower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

bool Cond1(ll x) {
	while (x / 10 > 0) {
		x /= 10;
		if (!CheckPrime(x)) return 0;
	}
	
	return 1;
}

bool Cond2(ll x) {
	ll tmp = x * 10;
	for (int i = 0; i <= 9; ++i) 
		if (CheckPrime(tmp + i)) return 1;
		
	return 0;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    cnt[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cnt[i] = cnt[i - 1];
    	
    	cin >> a[i];
    	
    	if (!CheckPrime(a[i])) continue;
    	
    	if (Cond1(a[i]) && Cond2(a[i])) cnt[i]++;
    }
    
    cin >> t;
    
    while (t--) {
    	ll l, r;
    	cin >> l >> r;
    	
    	cout << cnt[r] - cnt[l - 1] << endl;
    }
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hp_thpt_21_b
