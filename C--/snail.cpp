#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

ll n, m, ans = 0, a[maxn + 2], mxd = 0, mxa = 0, st;

int main() {
    nothing
    if (fopen("snail.inp", "r")) {
        freopen("snail.inp", "r", stdin);
        freopen("snail.out", "w", stdout);
    }
    cin >> m >> n;
	for (int i = 1; i <= n; ++i){
	 	cin >> a[i];
	 	mxa += a[i];
	 	mxd = max(mxd, mxa);
	 	
	 	st += a[i];
	 	st = max(0LL, st);
	}
	
	if (mxd > m || st > m) {
		cout << 0 << " ";
		for (int i = 1; i <= n; ++i){
			ans +=a[i];
			ans = max(ans, 0LL);
			
			if (ans >= m) {
				cout << i - 1;
				return 0;
			}
		}
	}
	
	if (mxa <= 0) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	
	ans = ceil((m - mxd - st)/ (double) mxa) + 1;
	cout << ans << " ";
	ans = (ans - 1) * mxa + st;
	

	
	for (int i = 1; i <= n; ++i){
		ans += a[i];
		if (ans >= m){
			cout << i - 1;
			return 0;
		}
	}
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
