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

ll test, n, x, c, ans, pre[maxn + 2];
string s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n >> x;
    	cin >> s;
    	
    	s = '#' + s;
    	ans = c = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		if (s[i] == '0') c++;
    		else c--;
    		
    		pre[i] = c;
    	}
		
		if (c == 0) {
			if (x == 0) {
				cout << -1 << endl;
				continue;
			}
			
			bool ok = 1;
			for (int i = 1; i <= n; ++i) 
				if (pre[i] == x) {
					cout << -1 << endl;
					ok = 0;
					break;
				}
				
			if (!ok) continue;
			
			cout << 0 << endl;
			continue;
		}
		
		for (int i = 1; i <= n; ++i) {
			if ((x - pre[i]) % c == 0 && ((x >= pre[i] && c > 0) || (x <= pre[i] && c < 0)))
				ans++;
		}
		
		if (x == 0) cout << ans + 1 << endl; 
		else cout << ans << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1295/B
