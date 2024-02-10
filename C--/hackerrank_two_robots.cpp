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

ll t, m, n, a, b, dp[maxn + 2], r[4];
ll res = 0, tmp = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> m >> n; 
    	
    	for (int i = 0; i <= m + 2; ++i) dp[i] = 0;
    	res = 0; tmp = 0; r[1] = r[2] = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a >> b;
    		
    		res = dp[0] + abs(a - b);
    		
    		for (int j = 1; j <= m; ++j) {
    			if (dp[j] != 0) {
	    			tmp = dp[j] + abs(j - a) + abs(a - b);
	    			res = min(res, tmp);
    			}
    		}
    		
    		if (r[2] == 0) tmp = abs(a - b);
    		else tmp = abs(r[2] - a) + abs(a - b);
    		
    		dp[0] += tmp;
    		
    		for (int j = 1; j <= m; ++j) {
    			if (dp[j] != 0) dp[j] += tmp;
    		}
    		
    		if (dp[r[2]] == 0 || dp[r[2]] > res) dp[r[2]] = res;
    		
    		r[2] = b;
    	}
    	
    	res = dp[0];
    	
    	for (int i = 1; i <= m; ++i) {
    		if (dp[i] != 0) res = min(res, dp[i]);
    	}
    	
    	cout << res << endl;
    }
    
    
    return 0;
}

// https://www.hackerrank.com/challenges/two-robots/problem?isFullScreen=true