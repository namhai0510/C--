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

ll test;
ll n, a[maxn + 2], mx_val;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	
    	if (n == 2) {
    		cout << max(a[1] + a[2], 2 * abs(a[1] - a[2])) << endl;
    		continue;
    	}
    	else if (n == 3) {
    		cout << max({a[1] + a[2] + a[3], abs(a[2] - a[1]) * 3, abs(a[3] - a[2]) * 3, a[1] * 3, a[3] * 3}) << endl;
    		continue;
    	}
    	
    	mx_val = 0;
    	for (int i = 1; i <= n; ++i)
    		mx_val = max(mx_val, a[i]);
    	
    	cout << n * mx_val << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1763/C
