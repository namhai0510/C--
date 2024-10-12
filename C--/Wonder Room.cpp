#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, a, b;
ll S, newa, newb;

bool Swap = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> a >> b;
    
    if (6 * n <= a * b) {
    	cout << a * b << endl;
    	cout << a << " " << b << endl;
    	return 0;
    }
    
    if (a > b) swap(a, b), Swap = 1;
    
    S = +oo;
	for (ll i = a; i * i <= 6 * n; ++i) {
		ll tmp = 6 * n / i;
		
		if (tmp * i < 6 * n) tmp++;
		
		if (tmp < b) continue;
		
		if (tmp * i < S) {
			S = tmp * i;
			newa = i;
			newb = tmp;
		}
	}
    
    if (Swap) swap(newa, newb);
    
    cout << S << endl;
    cout << newa << " " << newb << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/466/B