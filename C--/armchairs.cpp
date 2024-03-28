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
const int maxa = 5e3 + 5;

ll n, a[maxn + 2];

vector<ll> st;
ll dp[maxa + 2][maxa + 2], m;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	if (a[i] == 1) st.pb(i);
    }
    m = st.size();
    
    for (int i = 1; i <= n + 2; ++i) {
    	for (int j = 1; j <= m + 2; ++j) {
    		dp[i][j] = +oo;
    	}
    }
    dp[1][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= m; ++j) {
    		if (dp[i][j] == +oo) continue;
    		
    		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    		if (j < m && a[i] == 0)
		 		dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(st[j] - i));
    	}
    }
    
    cout << dp[n + 1][m] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1525/D