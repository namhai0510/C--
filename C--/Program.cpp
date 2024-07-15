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

struct Data {
	ll neu, mx, mn;
};

ll test, n, q, a[maxn + 2];
string s;
Data suf[maxn + 2], pre[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n >> q;
    	
    	cin >> s;
    	s = '#' + s;
    	
    	for (int i = 0; i <= n + 1; ++i) {
    		pre[i].mx = pre[i].mn = pre[i].neu = 0;
    		suf[i].mx = suf[i].mn = suf[i].neu = 0;
    	}
    	
    	for (int i = 1; i <= n; ++i) {
    		a[i] = (s[i] == '+' ? 1 : -1);
    		
    		pre[i].neu = pre[i - 1].neu + a[i];
    		
    		pre[i].mx = max(pre[i - 1].mx, pre[i].neu);
    		pre[i].mn = min(pre[i - 1].mn, pre[i].neu);
    	}
    	
    	for (int i = n; i >= 1; --i) {
    		suf[i].mx = max(suf[i + 1].mx + a[i], suf[i].mx);
    		suf[i].mn = min(suf[i + 1].mn + a[i], suf[i].mn);
    	}
    	
    	for (int j = 1; j <= q; ++j) {
    		ll l, r;
    		cin >> l >> r;
    		
    		ll MAX = max(pre[l - 1].mx, pre[l - 1].neu + suf[r + 1].mx);
    		ll MIN = min(pre[l - 1].mn, pre[l - 1].neu + suf[r + 1].mn);
    		
    		cout << MAX - MIN + 1 << endl;
    	}
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1473/D
