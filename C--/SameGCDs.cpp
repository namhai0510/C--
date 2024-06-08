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
const int base = 31;

ll test, a, b;

ll Phi(ll x) {
	ll ret = x;
	
	for (ll i = 2; i * i <= x; ++i) {
		if(x % i == 0) ret = ret / i * (i - 1);
		
		while (x % i == 0) x /= i;
	}
	
	if (x > 1) ret = ret / x * (x - 1);
	return ret;
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> a >> b;
    	
    	ll G = __gcd(a, b);
    	
		b /= G;
		cout << Phi(b) << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1295/D