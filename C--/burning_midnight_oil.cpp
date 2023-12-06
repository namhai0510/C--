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

bool Calc(ll v) {
	ll res = 1, cnt = 0;
	
	while (v / res > 0) {
		// cout << res << endl;
		cnt += v / res;
		res = res * k;
	}
	
	if (cnt >= n) return 1;
	else return 0;
}

ll Bs() {
	ll l = 1, r = n * k, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		
		// cout << l << " " << r << " " << mid << " " << Calc(mid) << endl;
		if (Calc(mid) == 1) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("burning_midnight_oil.inp", "r")) {
        freopen("burning_midnight_oil.inp", "r", stdin);
        freopen("burning_midnight_oil.out", "w", stdout);
    }
    cin >> n >> k;
    
    cout << Bs() << endl;
    
    // cout << Calc(Bs()) << endl;
    return 0;
}