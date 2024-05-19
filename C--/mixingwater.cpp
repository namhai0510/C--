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

ll test, h, c, t;

long double f(int x) {
	return (long double)(h + c) / 2 + (long double)(h - c) / x / 2 - t; 
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> h >> c >> t;
    	
    	if (t == h) {
    		cout << 1 << endl;
    		continue;
    	}
    	else if (h + c - 2 * t >= 0) {
    		cout << 2 << endl;
    		continue;
    	}
    	
    	ll k = (h - c) / (2 * t - h - c);
    	
    	if (k % 2 == 0) k++;
    	
    	if (f(k + 2) > -f(k))
    		cout << k + 2 << endl;
    	else
    		cout << k << endl;
    	
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1359/C
