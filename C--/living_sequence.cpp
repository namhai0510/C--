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

ll t, k, dp[32][5];
string a;

void Reset() {
	for (int i = 0; i <= 30; ++i) {
		for (int j = 0; j <= 3; ++j) dp[i][j] = -1;
	}
}

ll Calc(int pos, int f) {
    if (pos == a.size()) return 1;

    if (dp[pos][f] != -1) return dp[pos][f];

    ll ans = 0, e;
    if (f == 1) e = 9;
    else e = a[pos] - '0';
    
    for (int i = 0; i <= e; ++i){
        if (i == 4) continue;
        ans += Calc(pos + 1, f | (i < e));
    }

	dp[pos][f] = ans;
	
    return ans;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> k;
    	
    	ll l = 0, r = +oo, mid;
    	while (l <= r) {
    		Reset();
    		mid = (l + r) / 2;
    		
    		a = to_string(mid);
    		ll val = Calc(0, 0);
    		
    		if (val > k) r = mid - 1;
    		else l = mid + 1;
    	}
    	
    	cout << r + 1 << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1811/E