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
    if (fopen("TBK.inp", "r")) {
        freopen("TBK.inp", "r", stdin);
        freopen("TBK.out", "w", stdout);
    }
    cin >> n >> m;
}

void solve() {
    if (n < m && m - n < n) {
        if ((n - m + n) % 2 == 0) 
            cout << (n - m + n) / 2;
        else 
            cout << (n - m + n) / 2 + 1;
    } else if (n > m) {
        if (m % 2 == 0) 
            cout << m / 2 - 1;
        else 
            cout << m / 2;
    } else {
        cout << 0;
    }
}

int main() {
    inputData();
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
