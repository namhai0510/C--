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

ll n, S, tmp = 0, ans = +oo;
ll a[maxn + 2];
int main() {
    nothing
    if (fopen("KHLT.inp", "r")) {
        freopen("KHLT.inp", "r", stdin);
        freopen("KHLT.out", "w", stdout);
    }
    cin >> n >> S;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    ll l = 1, r = 1;
    
    while (r <= n + 1) {
    	if (tmp < S) {
    		tmp += a[r];
    		r++;
    	}
    	else {
    		ans = min(ans, (r - 1) - l + 1);
    		tmp -= a[l];
    		l++;
    		
    		// cout << l << " " << r - 1 << endl;
    	}
    }
    
    cout << ans << endl;
    return 0;
}
