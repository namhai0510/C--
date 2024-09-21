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

ll n, k, ans, t;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> k >> n;
    
    ans = 0;
    t = 0;
    
    for (int i = 1; i <= n; ++i) {
    	ll x, y;
    	cin >> x >> y;
    	
    	if (x * y <= t) {
			t -= x * y;
		}
		else {
			x -= t / y;
			
			int c1 = (x + k / y - 1) / (k / y);
			int c2 = x % (k / y);
			
			ans += c1;
			
			if (!c2) t = k - (k / y) * y;
			else t = k - y * c2;
		}
    }
    
    cout << ans << " " << t << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
