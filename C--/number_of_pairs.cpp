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

ll t, n, l, r, cnt = 0, a[maxn + 2];

ll Bs2 (ll x) {
	// be nhat lon hon bang
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    
    return l;
}

ll Bs3 (ll x) {
	// lon nhat be hon bang
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    
    return r;
}

int main() {
    nothing
    if (fopen("number_of_pairs.inp", "r")) {
        freopen("number_of_pairs.inp", "r", stdin);
        freopen("number_of_pairs.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cnt = 0;
    	cin >> n >> l >> r;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	sort(a + 1, a + 1 + n);
    	
    	// for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    	// cout << endl << "/ - /" << endl;
    	
    	// l <= a[i] + a[j] -> a[j] >= l - a[i];
    	// a[i] + a[j] <= r -> a[j] <= r - a[i];
    	
    	for (int i = 1; i <= n; ++i) {
    		ll it1 = Bs2(l - a[i]), it2 = Bs3(r - a[i]), res;
    		
    		res = (it2 - it1 + 1);
    		
    		if (a[i] * 2 >= l && a[i] * 2 <= r) res--;
    		// cout << i << " " << a[i] << " " << it1 << " " << it2 << " " << res << endl;
    		cnt += res;
    	}
    	cout << cnt / 2 << endl;
    	
    	// cout << "----------" << endl;
    }
    
    return 0;
}