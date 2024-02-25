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

ll n;
string s, res = "";

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    n = s.size();
    
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) {
    	string ans = "";
		ans = ans + s[i];
		// cout << ans << endl;
		
		ll val = stol(ans);
		if (val % 8 == 0) {
			cout << "YES" << endl;
			cout << ans << endl;
			return 0;
		}
    	for (int j = i + 1; j <= n; ++j) {
    		
    		string ans = "";
			ans = ans + s[i] + s[j];
			// cout << ans << endl;
			
			ll val = stol(ans);
			if (val % 8 == 0) {
				cout << "YES" << endl;
				cout << ans << endl;
				return 0;
			}
    		for (int k = j + 1; k <= n; ++k) {
    			string ans = "";
    			ans = ans + s[i] + s[j] + s[k];
    			// cout << ans << endl;
    			
    			ll val = stol(ans);
    			if (val % 8 == 0) {
    				cout << "YES" << endl;
    				cout << res << ans << endl;
    				return 0;
    			}
    		}
    	}
    	
    	res = res + s[i];
    }
    
    cout << "NO";
    return 0;
}

// https://codeforces.com/problemset/problem/550/C