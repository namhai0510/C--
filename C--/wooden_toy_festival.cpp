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

ll t, n, a[maxn + 2];

bool Check(ll mid) {
	ll cur = 1, cnt = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] - a[cur] > 2 * mid) {
			cur = i;
			cnt++;
		}
	}
	return (cnt <= 3);
}

ll Bs() {
	ll l = 0, r = a[n], mid, ans = 1e9;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("wooden_toy_festival.inp", "r")) {
        freopen("wooden_toy_festival.inp", "r", stdin);
        freopen("wooden_toy_festival.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	sort(a + 1, a + 1 + n);
    	
    	cout << Bs() << endl;
    }
    return 0;
}