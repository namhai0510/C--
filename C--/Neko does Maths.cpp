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

ll a, b, c, k, res, num;
vector<ll> f;

void factorized(ll x) {
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			f.pb(i);
			
			if (x / i != i) f.pb(x / i);
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b;
    
    if (a > b) swap(a, b);
    c = b - a;
    
    factorized(c);
    
    num = +oo;
    res = 0;
    
    for (ll val : f) {
    	if (a % val == 0) k = 0;
        else k = val - a % val;
        
        if (num > (b + k) * (a + k) / val) {
            res = k;
            num = (b + k) * (a + k) / val;
        }
        else if (num == (b + k) * (a + k) / val)
            res = min(res, k);
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1152/C
