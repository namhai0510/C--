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
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, a[maxn + 2], cnt = 0, ans = 0, tmp = 0;

int main() {
    nothing
    if (fopen("MINGROUP1.inp", "r")) {
        freopen("MINGROUP1.inp", "r", stdin);
        freopen("MINGROUP1.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	if (a[i] == 1) cnt++;
    }
    
    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i) {
    	if (a[i] == 1) tmp++;
    }
    ans = max(ans, tmp);
    
    for (int i = cnt + 1; i <= n; ++i) {
    	if (a[i - cnt] == 1) tmp--;
    	if (a[i] == 1) tmp++;
    	
    	ans = max(ans, tmp);
    	if (tmp == 5154) cout << i << endl;
    }
    
    // for (int i = 1; i <= n - cnt + 1; ++i) {
    	// tmp = 0;
    	// for (int j = i; j <= i + cnt - 1; ++j) {
    		// tmp += a[i];
    	// }
//     	
    	// if (tmp == 5154) cout << i << endl;
    // }
    // cout << ans << endl;
    cout << cnt - ans << endl;
    return 0;
}
