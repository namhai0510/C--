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

ll t, n, c, x[maxn + 2];

bool Calc(ll dis) {
	ll cnt = 1, lPos = x[1];
    for(int i = 1; i <= n; ++i) {
        if (x[i] - lPos >= dis) {
            cnt++;
            lPos = x[i];
            if (cnt >= c) return true;
        }
    }
    return false;
}

// tim vi tri dau tien ma so luong con bo co the dat duoc >= val
ll Bs(ll val) {
	ll l = 1, r = x[n] - x[1], mid, ans;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Calc(mid) == 1) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;

	}
	
	return ans;
}

int main() {
    nothing
    if (fopen("aggrcow.inp", "r")) {
        freopen("aggrcow.inp", "r", stdin);
        freopen("aggrcow.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> c;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> x[i];
    	}
    	sort(x + 1, x + 1 + n);
    	
    	cout << Bs(c) << endl;
    }
    return 0;
}