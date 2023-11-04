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
    
    for (int i = 1; i <= n; ++i) {
    	ll c, t; cin >> c >> t;
    	a[i] = c * t;
    	sum[i] = sum[i - 1] + a[i];
    }
    
    while (m--) {
    	ll v; cin >> v;
    	
    	ll it = lower_bound(sum + 1, sum + 1 + n, v) - sum;
    	cout << it << endl;
    }
    
	return 0;
}