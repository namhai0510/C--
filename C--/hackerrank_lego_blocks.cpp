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

ll t, h, w, wall[maxn + 2], danger[maxn + 2];
ll dp[maxa + 2][maxa + 2];

void PreCal() {
	dp[1][0] = 1;
	for (int j = 1; j <= maxa; ++j) {
    	
		dp[1][j] = dp[1][j - 1];
		
		if (j >= 2) dp[1][j] += dp[1][j - 2];
		if (j >= 3) dp[1][j] += dp[1][j - 3];
		if (j >= 4) dp[1][j] += dp[1][j - 4];
		dp[1][j] %= modd ;
	}
	
	for (int i = 2; i <= maxa; ++i) {
		for (int j = 1; j <= maxa; ++j) {
			dp[i][j] = dp[i - 1][j] * dp[1][j] % modd;
		}
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    PreCal();
    cin >> t;

    while (t--) {
    	cin >> h >> w;
    	
    	danger[1] = 0;
    	wall[1] = 1;
    	
    	for (int i = 1; i <= w; ++i) {
    		danger[i] = 0;
    		
    		for (int j = 1; j < i; ++j) {
    			danger[i] += dp[h][i - j] * wall[j];
    			danger[i] %= modd;
    		}
    		wall[i] = (dp[h][i] + modd - danger[i]) % modd;
    	}
    	
    	cout << wall[w] << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/lego-blocks/problem?isFullScreen=true

