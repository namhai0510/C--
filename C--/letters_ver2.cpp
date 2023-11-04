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

ll n, m, a[maxn + 2], sum[maxn + 2];

int main() {
    nothing
    if (fopen("letters.inp", "r")) {
        freopen("letters.inp", "r", stdin);
        freopen("letters.out", "w", stdout);
    }
    cin >> n >> m;
    
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	sum[i] = sum[i - 1] + a[i];
    }
    
    while (m--) {
    	ll val; cin >> val;
    	
    	ll l = 1, r = n, mid;
    	while (l <= r) {
    		mid = (l + r) / 2;
    		if (sum[mid] >= val) {
    			r = mid - 1;
    		}
    		else l = mid + 1;
    	}
    	cout << l << " " << val - sum[l - 1] << endl;
    }
    
	return 0;
}