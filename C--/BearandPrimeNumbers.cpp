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
const ll maxn = 1e7 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, test;
ll x[maxn + 2], pre[maxn + 2], fct[maxn + 2];

void Sieve() {
	for (int i = 1; i <= maxn; ++i) fct[i] = i;
	
	for (int i = 2; i * i <= maxn; ++i)
		if (fct[i] == i) 
			for (int j = i * i; j <= maxn; j += i)
				if (fct[j] == j) fct[j] = i;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Sieve();
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i];
    	
    	ll val = x[i];
    	while (val > 1) {
    		pre[fct[val]]++;
    		ll f = fct[val];
    		while (val % f == 0) val /= f;
    	}
    }
    
    for (int i = 1; i <= maxn; ++i) pre[i] += pre[i - 1];
    
    cin >> test;
    while (test--) {
    	ll l, r;
    	cin >> l >> r;
    	
    	cout << pre[min(maxn, r)] - pre[min(maxn, l) - 1] << endl;
    }
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/385/C
