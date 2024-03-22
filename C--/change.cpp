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
const int maxn = 1e4 + 5;
const int maxa = 2e3 + 5;

ll s, n, a[maxn + 2];
ll f[maxn + 2], ans = +oo, m = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s >> n;
    
    ans = s;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    // f[i] : so xu phai tra lai de nhan duoc i dong
    for (int i = 1; i <= maxn + 2; ++i) f[i] = i;
    
    f[0] = 0;
    for (int i = 1; i <= maxn + 2; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (i >= a[j]) 
    			f[i] = min(f[i], f[i - a[j]] + 1);
    			
    		if (i >= s)
    			ans = min(ans, f[i] + f[i - s]);
    	}
    }
    
    cout << ans << endl;
    return 0;
}
