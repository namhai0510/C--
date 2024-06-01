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

ll n, x, y;
ll a[maxn + 2], tmp[maxn + 2];
ll ans = 0;

bool Solve(ll num) {
	for (int i = 1; i <= n; ++i) tmp[i] = a[i] - num * y;
	
	ll differ = x - y, cnt = 0;
	if (differ == 0) {
		for (int i = 1; i <= n; ++i) if (tmp[i] >= 0) return false;
		return true;
	}
	else if (differ > 0) {
		for (int i = 1; i <= n; ++i) {
			if (tmp[i] >= 0) cnt += tmp[i] / (x - y) + 1;
			if (cnt > num) return false;
		}
		
		if (cnt <= num) return true;
		
		return false;
	}
	else if (differ < 0) {
		
		for (int i = 1; i <= n; ++i) if (tmp[i] >= 0) return false;
		
		for (int i = 1; i <= n; ++i) {
			cnt += (abs(tmp[i]) - 1) / (y - x);
			
			if (cnt >= num) return true;
		}
		
		if (cnt >= num) return true;
		
		return false;
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> x >> y;
    
    // cout << x - y << endl;
    
    ll mx = -oo;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	tmp[i] = a[i];
    	mx = max(mx, a[i]);
    }
    
    if (mx < 0) cout << 0, exit(0);
    
    if (n == 1) cout << a[1] / x + 1, exit(0);
    
    ll l = 1, r = mx / min(x, y) + 1, mid;
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	if (Solve(mid)) r = mid - 1;
    	else l = mid + 1;
    	
    	// cout << mid << " " << Solve(mid) << endl;
    }
    
    cout << l << endl;
    return 0;
}
