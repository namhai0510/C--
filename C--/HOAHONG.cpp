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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, k;
ll a[maxn + 2], b[maxn + 2];
ll cnt, ret, mxc = 0, l, r, mid, res = 0;

bool Check(ll x) {
	ret = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) b[i] = a[i];
	
	int i = n;
	
	while (i > 0) {
		if (b[i] >= mid) {
			ret++;
			--i;
			continue;
		}
		
		cnt = x;
		
		while (i > 0 && cnt > 0) {
			ll tmp = min(cnt, b[i]);
			cnt -= tmp;
			b[i] -= tmp;
			if (b[i] <= 0) --i;
			
			// for (int p = 1; p <= n; ++p) cout << b[p] << " ";
			// cout << endl;
			// cout << endl << cnt << endl;
		}
		
		if (cnt == 0) ret++;
	}
	
	// res = max(res, ret);
	// cout << ret << endl;
	
	return (ret >= k);
}

int main() {
    nothing
    if (fopen("HOAHONG.inp", "r")) {
        freopen("HOAHONG.inp", "r", stdin);
        freopen("HOAHONG.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i], mxc += a[i];
    sort(a + 1, a + 1 + n);
    
    mxc = mxc / k;
    
    l = 1, r = mxc;
    
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	// cout << l << " " << r << " " << mid << endl;
    	if (Check(mid)) l = mid + 1, res = mid;
    	else r = mid - 1;
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
