#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e17 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
ll n, k;

ll Bs(ll val) {
	ll l = 1, r = n + 1, mid, ans;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		ll v = mid * (mid + 1) / 2;
		if (v >= k && (n - mid) <= (v - k)) {
			r = mid - 1;
			ans = v;
		}
		else l = mid + 1;
		
		// cout << l << " " << r << endl;
	}
	
	return ans;
	
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    // x * (x + 1) / 2 + (n - x) == k
    
    cout << Bs(k) - k << endl;
	
    return 0;
}
