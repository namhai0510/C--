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

ll n, k, a[maxn + 2];
ll psum[maxn + 2];

ll Calc(ll length) {
	ll sMax = 0;
	for (int i = 1; i <= n - length + 1; ++i) {
		sMax = max(sMax, psum[i + length - 1] - psum[i - 1]);
	}
	
	return sMax;
}

int main() {
    nothing
    if (fopen("MaxiSubArr.inp", "r")) {
        freopen("MaxiSubArr.inp", "r", stdin);
        freopen("MaxiSubArr.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    }
    
    int l = 1, r = n, mid;
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	// cout << l << " " << r << " " << mid << " " << Calc(mid) << endl;
    	
    	if (Calc(mid) <= k) l = mid + 1;
    	else r = mid - 1; 
    }
    
    if (r != 0) cout << r << endl;
    else cout << "-1" << endl;
    return 0;
}
