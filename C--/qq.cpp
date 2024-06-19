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

ll n, tvx, tvy, ans, res;
ll x[maxn + 2], y[maxn + 2], a[maxn + 2], b[maxn + 2], hx, hy;

int main() {
    nothing
    if (fopen("qq.inp", "r")) {
        freopen("qq.inp", "r", stdin);
        freopen("qq.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    
    tvx = tvy = 0;
    for (int i = 1; i <= n; i++) {
        tvx += abs(x[i] - x[n / 2 + 1]);
    }
    for (int i = 1; i <= n; i++) {
        tvy += abs(y[i] - y[n / 2 + 1]);
    }
    
    for (int i = 1; i <= n; i++) {
        a[i] = x[i] - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = y[i] - i + 1;
    }
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    ll pos1 = a[n / 2];
    ll pos2 = b[n / 2];
    hx = 0, hy = tvy;
    for (int i = 1; i <= n; i++) {
        hx += abs(a[i] - pos1);
    }
    ans = hx + hy;
    hx = tvx, hy = 0;
    for (int i = 1; i <= n; i++) {
        hy += abs(b[i] - pos2);
    }
    res = hx + hy;
    
    cout << min(ans, res);
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
