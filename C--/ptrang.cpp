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

ll n, L, w[maxn + 2];
ll f[maxn + 2], tmp[maxn + 2];
ll ans = 6000005;

void back(ll pos, ll x, ll res) {
	if (pos > n) {
		ans = min(ans, max(res, L - x));
		// for (int i = 1; i <= n; ++i) cout << f[i] << " ";
		// cout << max(res, L - x) << endl;
		return;
	}
	
	for (int i = (x + w[pos] > L); i <= (pos > 1); ++i) {
		bool check = 1;
		
		ll tp = x * (1 - i) + w[pos];
		f[pos] = i;
		
		if (i == 1) {
			if (tmp[pos - 1] > max(res, (L - x))) {
				tmp[pos - 1] = max(res, (L - x)); 
			}
			else check = 0;
		}
		
		if (check) back(pos + 1, tp, max(res, (L - x) * i));
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    
    for (int i = 1; i <= n; ++i) tmp[i] = L;
    back(1, 0, 0);
    
    // for (int i = 1; i <= n; ++i) cout << tmp[i] << " ";
    
    cout << ans << endl;
    return 0;
}
