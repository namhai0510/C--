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

ll n, l, r, a[maxn + 2];
ll res = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> l >> r;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for(int i = 1; i <= n; ++i) {
        ll st = lower_bound(a + 1, a + n + 1, L - a[i]) - a - 1;
        ll en = upper_bound(a + 1, a + n + 1, R - a[i]) - a - 1 - 1;
        
        if (st <= en) res += (en - st + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        if (L <= 2 * a[i] && 2 * a[i] <= R) res++;
    }
    
    cout << res / 2 << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
