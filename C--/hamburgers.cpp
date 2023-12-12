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

string recipe;
ll n, rub, ne = 0, c[4] = {0, 0, 0, 0}, cnt = 0, money;
pair<ll, ll> ig[4];

ll price (ll x) {
	ll f1 = max(x * c[1] - ig[1].fi, 1LL * 0);
	ll f2 = max(x * c[2] - ig[2].fi, 1LL * 0);
	ll f3 = max(x * c[3] - ig[3].fi, 1LL * 0);
 
	return (f1 * ig[1].se + f2 * ig[2].se + f3 * ig[3].se);
}

ll Bs() {
	ll l = 1, r = rub + 1000, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		ll val = price(mid);
		if (val <= rub) {
			l = mid + 1;
			ans = mid;
			
			// cout << money << " " << rub << " " << mid << endl;
		}
		else r = mid - 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("hamburgers.inp", "r")) {
        freopen("hamburgers.inp", "r", stdin);
        freopen("hamburgers.out", "w", stdout);
    }
    /// INPUT
    cin >> recipe;
    n = recipe.size();
    recipe = '#' + recipe;
    
    ig[1].fi = 0; ig[2].fi = 0; ig[3].fi = 0;
    for (int i = 1; i <= 3; ++i) {
    	cin >> ig[i].fi;
    }
    for (int i = 1; i <= 3; ++i) {
    	cin >> ig[i].se;
    }
    
    cin >> rub;
    /// SOLVE
    for (int i = 1; i <= n; ++i) {
    	if (recipe[i] == 'B') c[1]++;
    	else if (recipe[i] == 'S') c[2]++;
    	else c[3]++;
    }
    
    ne = ig[1].se * c[1] + ig[2].se * c[2] + ig[3].se * c[3];
    
    cout << Bs() << endl;
    
    return 0;
}