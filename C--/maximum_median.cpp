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

ll n, k, a[maxn + 2];

bool Check(ll val) {
	ll sum = 0;
	for (int i = n / 2 + 1; i <= n; ++i) {
		if (a[i] < val) sum += val - a[i];
	}
	
	return (sum <= k);
}

ll Bs() {
	ll l = 1, r = +oo, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
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
    if (fopen("maximum_median.inp", "r")) {
        freopen("maximum_median.inp", "r", stdin);
        freopen("maximum_median.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    cout << Bs() << endl;
    
    return 0;
}