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

ll t, n, a[maxn + 2], ps[maxn + 2], ans = 0;

int Bs3 (ll x) {
	int l, r, mid;
    l = 1; r = n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ps[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    
    return r;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	ans = 0;
    	cin >> n;
    	
    	ps[0] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		ps[i] = ps[i - 1] + a[i];
    	}
    	
    	ll sum = 0;
    	for (int i = n; i >= 1; --i) {
    		sum += a[i];
    		
    		ll it = Bs3(sum);
    		
    		if (it < i && ps[it] == sum) ans = max(ans, n - i + 1 + it); 
    	}
    	cout << ans << endl;
    }
    
    return 0;
}