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

string s;
ll n, a[50], dp[50][50], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    
    n = s.size();
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) {
    	ll c = s[i] - 'a' + 1;
    	
    	for (int j = 1; j <= 26; ++j) {
    		dp[j][c] += a[j];
    	}
    	
    	a[c]++;
    }
    
    for (int i = 1; i <= 26; ++i) ans = max(ans, a[i]);
    
    for (int i = 1; i <= 26; ++i) {
    	for (int j = 1; j <= 26; ++j) {
    		ans = max(ans, dp[i][j]);
    	}
    }
    
    cout << ans << endl;
    
    return 0;
}

// https://codeforces.com/problemset/problem/1307/C