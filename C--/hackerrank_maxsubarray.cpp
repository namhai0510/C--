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

ll t, n, a[maxn + 2], dp[maxn + 2];
ll ans[3];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	ans[1] = -oo;
    	ans[2] = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		dp[i] = max(a[i], dp[i - 1] + a[i]);
    		ans[1] = max(ans[1], dp[i]);
    	}
    	
    	sort(a + 1, a + 1 + n);
    	
    	if (a[n] <= 0) ans[2] = a[n];
    	else {
    		for (int i = n; i >= 1; --i) {
    			if (a[i] > 0) ans[2] += a[i];
    			else break;
    		}
    	}
    	
    	cout << ans[1] << " " << ans[2] << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/maxsubarray/problem?isFullScreen=true
