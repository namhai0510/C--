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

ll n, res, a[maxn + 1], mx1[maxn + 1], mx2[maxn + 1], mn1[maxn + 1], mn2[maxn + 1];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mx1[0] = mx2[n + 1] = LLONG_MIN;
    mn1[0] = mn2[n + 1] = LLONG_MAX;

    for (int i = 1; i <= n - 2; ++i) {
        mx1[i] = max(mx1[i - 1], a[i]);
        mn1[i] = min(mn1[i - 1], a[i]);
    }

    for (int i = n; i >= 3; --i) {
        mx2[i] = max(mx2[i + 1], a[i]);
        mn2[i] = min(mn2[i + 1], a[i]);
    }

    res = LLONG_MIN;
    for (int i = 2; i <= n - 1; ++i) 
        res = max({res, mx1[i - 1] * mx2[i + 1] * a[i], mn1[i - 1] * mn2[i + 1] * a[i], mx1[i - 1] * mn2[i + 1] * a[i], mn1[i - 1] * mx2[i + 1] * a[i]});

    cout << res << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
