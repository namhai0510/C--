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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, a[maxn + 2], res;

int main() {
    nothing
    if (fopen("SODU.inp", "r")) {
        freopen("SODU.inp", "r", stdin);
        freopen("SODU.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    for(int i = 1; i <= n; i++) {
        for(int j = a[i]; j <= a[n]; j += a[i]) {
            ll x = lower_bound(a + 1, a + n + 1, j + a[i]) - a - 1;
            ///cout << j << " " << j + a[i] << " " << x << " " << a[x] << endl;
            res = max(res, a[x] % a[i]);
        }
    }
    
    cout << res << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
