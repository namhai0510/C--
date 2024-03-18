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

ll n, a[maxn + 2], S = 0;
ll dp[maxn + 2][3];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	S += a[i];
    }
    
    dp[n][0] = 0;
    dp[n][1] = a[n];
    
    for (int i = n - 1; i >= 1; --i) {
    	dp[i][0] = min(dp[i + 1][0] + a[i], dp[i + 1][1]);
    	dp[i][1] = max(dp[i + 1][0] + a[i], dp[i + 1][1]);
    }
    
    cout << S - dp[1][1] << " " << dp[1][1];
    return 0;
}

// https://codeforces.com/problemset/problem/859/C