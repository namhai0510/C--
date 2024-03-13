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

ll n, x[maxn + 2], h[maxn + 2];
ll dp[maxn + 2][3];
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i] >> h[i];
    }
    
    dp[1][0] = dp[1][1] = 1;
    
    for (int i = 2; i <= n; ++i) {
    	dp[i][0] = max(dp[i - 1][0] + (x[i] - x[i - 1] > h[i]), 
    		dp[i - 1][1] + (x[i] - x[i - 1] - h[i - 1] > h[i]));
    	
    	if (i == n) {
    		dp[i][1] = dp[i - 1][1] + 1;
    	}
    	else {
    		dp[i][1] = max(dp[i][0], dp[i - 1][1] + (x[i + 1] - x[i] > h[i]));
    	}
    }
    
    cout << dp[n][1] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/545/C