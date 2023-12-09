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

ull n, k;
pair<ull, ull> x[maxn + 2];

bool Check(ll val) {
	ll lack = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (val * x[i].fi > x[i].se)
			lack += val * x[i].fi - x[i].se;
	}
	
	return (lack <= k);
}

ll Bs() {
	ll l = 1, r = +oo, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("magic_powder.inp", "r")) {
        freopen("magic_powder.inp", "r", stdin);
        freopen("magic_powder.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i].fi;
    }
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i].se;
    }
    
    cout << Bs() << endl;
    return 0;
}