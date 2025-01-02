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

ll n, s, res = 0;
pair<ll, ll> a[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> s;
    
    for (int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
        if (a[i].fi > s) break;
        
        if (a[i].fi <= s) {
            res++;
            s += a[i].se;
        }
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
