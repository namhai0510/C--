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
const int base = 31;

ll test, p, f, cnts, cntw, s, w;
ll ans = 0, nums, numw;

ll valid(ll s, ll w, ll cs, ll cw, ll val) {
	if (s > w)
        return valid(w, s, cw, cs, val);
 
    if (s * cs >= val)
        return val / s;
 
    return cs + min((val - s * cs) / w, cw);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> p >> f;
    	cin >> cnts >> cntw;
    	cin >> s >> w;
    	
    	ans = 0;
    	for (nums = 0; nums <= cnts; nums++) {
    		if (nums * s <= p) {
    			numw = min((p - nums * s) / w, cntw);
    			
    			ans = max(ans, nums + numw + valid(s, w, cnts - nums, cntw - numw, f));
    		}
    	}
    	
    	cout << ans << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1400/B?csrf_token=a7c99a181cd3eb224070f642bae6c097