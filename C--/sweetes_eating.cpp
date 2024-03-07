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

ll n, m, a[maxn + 2], ps[maxn + 2], dp[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	dp[i] = 0;
    }
    sort(a + 1, a + 1 + n);
    
    // for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    // cout << endl;
    
    for (int i = 1; i <= n; ++i) {
    	ps[i] = ps[i - 1] + a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
    	if (i <= m) dp[i] += ps[i];
    	else dp[i] += dp[i - m] + ps[i];
    }
    
    for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
    
    return 0;
}

// https://codeforces.com/problemset/problem/1253/C