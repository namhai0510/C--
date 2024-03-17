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
const ll modd = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, k;
ll dp[70][70][5];

void Reset() {
	for (int i = 0; i <= 65; ++i) {
		for (int j = 0; j <= 65; ++j) {
			for (int k = 0; k <= 3; ++k) dp[i][j][k] = 0;
		}
	}
	
	dp[0][0][2] = 1;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	Reset();
    	
    	cin >> n;
    	k = n / 2;
    	
    	for (int i = 0; i <= k; ++i) {
    		for (int j = 0; j <= k; ++j) {
    			for (int t = 0; t <= 2; ++t) {
    				int turn = (i + j) % 4;
    				
    				if (turn == 0 || turn == 3) {
    					if (i < k) {
    						if (t == 2) 
								dp[i + 1][j][0] += dp[i][j][t];
							else 
								dp[i + 1][j][t] += dp[i][j][t];
    					}
    					if (j < k) {
    						dp[i][j + 1][t] += dp[i][j][t];
    					}
    				}
    				else {
    					if (i < k) {
    						dp[i + 1][j][t] += dp[i][j][t];
    					}
    					if (j < k) {
    						if (t == 2) 
    							dp[i][j + 1][1] += dp[i][j][t];
    						else 
    							dp[i][j + 1][t] += dp[i][j][t];
    					}
    				}
    			}
    		}
    	}
    	
    	for (int t = 0; t <= 2; ++t) {
    		cout << dp[k][k][t] % modd << " ";
    	}
    	cout << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1739/C