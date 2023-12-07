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

ll n, m, k;

bool Check(ll val) {
	ll ans = 0, numl = k - 1, numr = n - k;
	
	if (val > numl) ans += (val + val - numl) * (numl + 1) / 2 - val;
	else ans += (val + 1) * val / 2 + numl - (val + val - 1);
	
	if (val > numr) ans += (val + val - numr) * (numr + 1) / 2 - val;
	else ans += (val + 1) * val / 2 + numr - (val + val - 1);
	
	return (m - ans >= val);
}

ll Bs() {
	ll l = 1, r = m, mid, ans = 0;
	
		while (l <= r) {
		mid = (l + r) / 2;
		
		// cout << l << " " << r << " " << mid << " " << Check(mid) << endl;
		if (Check(mid) == 1) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("frodo_and_pillows.inp", "r")) {
        freopen("frodo_and_pillows.inp", "r", stdin);
        freopen("frodo_and_pillows.out", "w", stdout);
    }
    cin >> n >> m >> k;
    
    cout << Bs() << endl;
    
    return 0;
}

