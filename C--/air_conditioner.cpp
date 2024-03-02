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

ll q, n, m, t[maxn + 2], l[maxn + 2], h[maxn + 2];
ll minh = 0, maxh = 0, p = 0;
bool ok = true;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> q;
    
    while (q--) {
    	cin >> n >> m;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> t[i] >> l[i] >> h[i];
    	}
    	
    	minh = m; maxh = m; p = 0;
    	ok = true;
    	
    	for (int i = 1; i <= n; ++i) {
    		maxh += (t[i] - p); minh -= (t[i] - p);
    		
    		if (maxh < l[i] || minh > h[i]) {
    			ok = false;
    			break;
    		}
    		
    		maxh = min(maxh, h[i]); minh = max(minh, l[i]);
    		p = t[i];
    	}
    	
    	if (ok) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1304/C
