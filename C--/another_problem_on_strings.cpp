#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, a[maxn + 2], ans = 0;
string s;

ll Bs2 (ll val, ll pre) {
	ll l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] - a[pre - 1] >= val) r = mid - 1;
		else l = mid + 1;
	}
	
	return l;
}

ll Bs3 (ll val, ll pre) {
	ll l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] - a[pre - 1] > val) r = mid - 1;
		else l = mid + 1;
	}
	
	return r;
}

int main() {
    nothing
    if (fopen("another_problem_on_strings.inp", "r")) {
        freopen("another_problem_on_strings.inp", "r", stdin);
        freopen("another_problem_on_strings.out", "w", stdout);
    }
    cin >> k >> s;
    s = '#' + s; n = s.size() - 1;
    a[0] = 0; a[n + 1] = k;
    
    for (int i = 1; i <= n; ++i) {
    	a[i] = a[i - 1];
    	if (s[i] == '1') a[i]++;
    }
    
    // for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    // cout << endl;
    
    for (int i = 1; i <= n; ++i) {
    	ll l = Bs2(k, i), r = Bs3(k, i);
    	
    	// cout << i << " " << l << " " << r << endl;
    	if (l <= n && a[r] - a[i - 1] == k && a[l] - a[i - 1] == k) ans += r - l + 1;
    }
    cout << ans << endl;
    
    return 0;
}