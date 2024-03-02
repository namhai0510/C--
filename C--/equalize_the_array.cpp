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

ll t, n, a[maxn + 2], C, sum = 0, ans;
map<ll, ll> cnt, mark;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	cnt.clear();
    	mark.clear();
    	    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		cnt[a[i]]++;
    	}
    	
    	for (auto it : cnt) {
    		mark[it.se]++;
    	}
    	
    	C = cnt.size();
    	ans = 0; sum = 0;
    	
    	for (auto it : mark) {
    		sum = it.fi * it.se;
    		C -= it.se;
    		
    		sum += it.fi * C;
    		
    		ans = max(ans, sum);
    		sum = 0;
    		
    		// cout << ans << endl;
    	}
    	
    	cout << n - ans << endl;
    	// cout << "----" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1490/F