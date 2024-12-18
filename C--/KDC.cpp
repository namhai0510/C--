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

ll m, n, a[maxn], res;

void inputData() {
    nothing
    if (fopen("KDC.inp", "r")) {
        freopen("KDC.inp", "r", stdin);
        freopen("KDC.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void sub1() {
    res = oo;
    for (int i = 2; i <= n; i++) {
        res = min(res, a[i] - a[i - 1]);
    }
    if (res % 2 == 0) cout << res / 2;
    else cout << res / 2 + 1;
}

void sub2() {
    if ((a[n] - a[1]) % 2 == 0) cout << (a[n] - a[1]) / 2;
    else cout << (a[n] - a[1]) / 2 + 1;
}

void solve() {
    if (m == n - 1) sub1();
    else sub2();
}

int main() {
    inputData();
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
