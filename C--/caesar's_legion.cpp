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
const ll modd = 1e8;
const int maxn = 1e6 + 5;
const int maxa = 2e2 + 5;

ll n[5], k[5];
ll dp[maxa + 2][maxa + 2][5];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n[1] >> n[2] >> k[1] >> k[2];
    dp[0][0][0] = dp[0][0][1] = 1;
    
    for (ll i = 0; i <= n[1]; ++i) {
    	for (ll j = 0; j <= n[2]; ++j) {
    		if (i == 0 && j == 0) continue;
    		
    		for (ll t = 1; t <= min(i, k[1]); ++t) 
    			dp[i][j][0] = (dp[i][j][0] + dp[i - t][j][1]) % modd;
    		for (ll t = 1; t <= min(j, k[2]); ++t)
    			dp[i][j][1] = (dp[i][j][1] + dp[i][j - t][0]) % modd;
    	}
    }
    
    cout << (dp[n[1]][n[2]][0] + dp[n[1]][n[2]][1]) % modd;
    return 0;
}

// https://codeforces.com/problemset/problem/118/D