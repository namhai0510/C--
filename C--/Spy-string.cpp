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

ll test;
ll n, m, cDif = 0;
string s[20], ans;
bool acpt, exist = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n >> m;
    	for (int i = 1; i <= n; ++i) cin >> s[i];
    	
    	ans = s[1];
    	exist = 0;
    	
    	for (int k = 0; k < m; ++k) {
    		if (exist) break;
    		char sv = ans[k];
    		
    		for (char x = 'a'; x <= 'z'; ++x) {
    			acpt = 1;
    			ans[k] = x;
    			
    			for (int i = 1; i <= n; ++i) {
    				cDif = 0;
    				for (int j = 0; j < m; ++j)
    					if (s[i][j] != ans[j]) cDif++;
    					
    				if (cDif > 1) {
    					acpt = 0;
    					break;
    				}
    			}
    			
    			if (acpt) {
    				exist = 1;
	    			cout << ans << endl;
	    			break;
	    		}
    		}
    		ans[k] = sv;
    	}
    	if (exist) continue;
    	
    	cout << "-1" << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1360/F
