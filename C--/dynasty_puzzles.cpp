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
string a[maxn + 2];

ll dp[30][30], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	ll l, r, len;
    	
    	len = a[i].size();
    	l = a[i][0] - 'a' + 1;
    	r = a[i][len - 1] - 'a' + 1;
    	
    	for (int j = 1; j <= 26; ++j) {
    		if (j != l && dp[j][l] == 0) continue;
    		
    		dp[j][r] = max(dp[j][r], dp[j][l] + len);
    	}
    	
    	dp[l][r] = max(dp[l][r], len);
    }
    
    for (int i = 1; i <= 26; ++i) {
    	ans = max(ans, dp[i][i]);
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/191/A