#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e13 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n;
pair<ll, ll> a[maxn + 2];
vector<ll> ans;

bool Check(ll pos) {
	ll s = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (i <= pos) s += a[i].fi;
		else {
			if (s >= a[i].fi) s += a[i].fi;
			else return 0;
		}
	}
	
	return 1;
}

ll Bs() {
	ll l = 1, r = a[n].fi, mid, ans;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 0) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	return l;
}

int main() {
    nothing
    if (fopen("accidental_victory.inp", "r")) {
        freopen("accidental_victory.inp", "r", stdin);
        freopen("accidental_victory.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	ans.clear();
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i].fi;
    		a[i].se = i;
    	}
    	sort(a + 1, a + 1 + n);
    	
    	ll it = Bs();
    	for (int i = it; i <= n; ++i) {
    		ans.pb(a[i].se);
    	}
    	sort(ans.begin(), ans.end());
    	
    	cout << ans.size() << endl;
    	for (auto i : ans) cout << i << " ";
    	cout << endl;
    }
    
    return 0;
}