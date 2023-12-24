#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, num, e, val, sum = 0, cnt[maxn + 2];
pair<ll, ll> a[maxn + 2];

ll dgnum(ll i, ll j) {
	if (m >= n) return m - i + j;
	else return n - j + i;
}
        
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    
    e = min(m, n);
    num = m + n - 1;
    
    val = 0;
    for (int i = 1; i <= (num + 1) / 2; ++i) {
    	if (val < e) val++;
    	a[i].fi = val;
    	cnt[i] = a[i].fi;
    }
    val = 0;
    for (int i = num; i >= (num + 1) / 2; --i) {
    	if (val < e) val++;
    	a[i].fi = val;
    	cnt[i] = a[i].fi;
    }
    
    sum = 0;
    for (int i = 1; i <= num; ++i) {
    	a[i].se = sum + 1;
    	sum += a[i].fi;
    	// cout << i << " " << a[i].fi << " " << a[i].se << " " << endl;
    }
    // cout << "-----" << endl;
    // for (int i = 1; i <= m; ++i) {
    	// for (int j = 1; j <= n; ++j) cout << dgnum(i, j) << " ";
    	// cout << "\n";
    // }
    // cout << "-----" << endl;
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		ll dg = dgnum(i, j);
    		if (m < n) dg = num - dg + 1;
    		cout << a[dg].se + (cnt[dg] - a[dg].fi) << " ";
    		a[dg].fi--;
    		
    	}
    	cout << "\n";
    }
    return 0;
}
