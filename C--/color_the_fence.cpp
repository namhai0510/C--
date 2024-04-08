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

ll v, a[15];
ll dp[maxn + 2][15], length = 0;
vector<ll> ans;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> v;
    
    for (int i = 1; i <= 9; ++i) cin >> a[i];
    
    for (ll i = 1; i <= v; ++i) {
    	for (int j = 1; j <= 9; ++j) {
    		if (i >= a[j]) {
    			dp[i][j] = 1;
    			
    			ll add = 0;
    			
    			for (int k = 1; k <= 9; ++k) {
    				add = max(add, dp[i - a[j]][k]);
    			}
    			
    			dp[i][j] += add;
    		}
    	}
    }
    
    for (int i = 1; i <= 9; ++i) {
    	length = max(length, dp[v][i]);
    }
    
    if (length == 0) {
    	cout << "-1";
    	exit(0);
    }
    
    while (length > 0) {
    	for (int i = 9; i >= 1; --i) {
    		if (dp[v][i] == length) {
    			ans.pb(i);
    			v -= a[i];
    			length--;
    			break;
    		}
    	}
    }
    
    for (auto digit : ans) cout << digit;
    return 0;
}

// https://codeforces.com/problemset/problem/349/B
