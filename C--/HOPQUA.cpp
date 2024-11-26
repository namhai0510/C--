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
const int maxn = 3e6;
const int maxa = 2e3;
const int base = 31;

ll n, k, a[maxn + 2];
ll ans = 0, tmp = 0;

int main() {
    nothing
    if (fopen("HOPQUA.inp", "r")) {
        freopen("HOPQUA.inp", "r", stdin);
        freopen("HOPQUA.out", "w", stdout);
    }
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    for (int i = 2; i <= n; ++i) {
    	tmp = upper_bound(a + 1, a + n + 1, (a[i - 1] + k)) - a - i;
    	ans += tmp * (tmp - 1) / 2;
    }
    
    cout << ans << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
