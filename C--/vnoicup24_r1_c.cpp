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

ll test, x, n;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> x;
		n = 1;
		
		while ((1 << n) - 2 <= x) ++n;
		--n;
		
		cout << n << endl;
		for (int i = 0; i < n; ++i) 
			cout << (1 << n) - (1 << i) - (1 << 0) << " ";
		cout << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/vnoicup24_r1_c
