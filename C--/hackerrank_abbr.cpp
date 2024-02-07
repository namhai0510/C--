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

int q, n, m, dp[maxa + 2][maxa + 2];
string a, b;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> q;
    
    while (q--) {
    	cin >> a >> b;
    	
		n = a.size(); m = b.size();
		a = '#' + a;
		b = '#' + b;
	
		for (int j = 0; j <= m; ++j){
	        if (j == 0) dp[0][j] = 1;
	        else dp[0][j] = 0;
	    }
	    
	    ll cnt = 0;
	    
	    for (int i = 1; i <= n; ++i){
	        if(a[i] >= 'A'&&a [i] <= 'Z'|| cnt == 1){
	            cnt = 1;
	            dp[i][0] = 0;
	        }
	        else dp[i][0] = 1; 
	    }
	    
	    for (int i = 1; i <= n; ++i) {
	        for (int j = 1; j <= m; ++j) {
	            if (a[i] == b[j]) {
	                dp[i][j] = dp[i - 1][j - 1];
	                continue;
	            }
	            else {
	                if (toupper(a[i]) == b[j]) {
	                    dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j];
	                    continue;
	                }
	            }
	            
	            if (a[i]>= 'A' && a[i] <= 'Z'){
	                dp[i][j] = 0;
	                continue;
	            }
	            else{
		            dp[i][j] = dp[i - 1][j];
		            continue; 
	            }
	        }
        }
        
        if (dp[n][m]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/abbr/problem?isFullScreen=true