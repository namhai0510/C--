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

ll n, a[maxn + 2], psum[maxn + 4];
vector<ll> divisor;

int main() {
    nothing
    if (fopen("xephang.inp", "r")) {
        freopen("xephang.inp", "r", stdin);
        freopen("xephang.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    }
    psum[n + 1] = +oo;
    
    ll sum = psum[n];
    
    for (int i = 1; i <= sqrt(sum); ++i) {
    	if (sum % i == 0) {
    		divisor.pb(i);
    		if (sum / i != i) divisor.pb(sum / i);
    	}
    }
    sort(divisor.begin(), divisor.end());
    
    ll ans;
    for (int i = 0; i < divisor.size(); ++i) {
    	// cout << divisor[i] << endl;
    	ll l = 1, val = divisor[i];
    	while (1) {
    		ll it = lower_bound(psum + l, psum + n, val) - psum;
    		
    		// cout << it << " " << psum[it] << " " << val << endl;
    		
    		if (psum[it] != val) {
    			break;
    		} 
    		else {
    			if (it == sum / val) {
					cout << val;
					return 0;
				}
    			l = it + 1;
    		}
    	}
    }
    
    return 0;
}