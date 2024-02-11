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

ll t, n, h[maxn + 2];

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
    		cin >> h[i];
    	}
    	
    	sort(h + 1, h + 1 + n);
    	
    	ll sum = 0, ans = 0;
    	
    	for (int i = n; i >= 1; --i) {
    		ans = max(ans, (i + 1) * sum);
    		sum += h[i];
    	}
    	ans = max(ans, sum);
    	
    	cout << ans << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/mandragora/problem?isFullScreen=true
