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
const int maxn = 1e5 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, k, d, l[maxn + 2], r[maxn + 2], a[maxn + 2];
ll R[maxn + 2][35];
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k >> d;
    for (int i = 1; i <= k; ++i) cin >> l[i] >> r[i];
    
    iota(a + 1, a + n + 1, 1);
    
    for (int i = 1; i <= k; ++i) 
        for(int j = l[i]; j <= r[i] && j <= r[i] - j + l[i]; ++j) 
            swap(a[j], a[r[i] - j + l[i]]);

    for (int i = 1; i <= n; ++i) R[i][0] = a[i];

    for (int s = 1; s <= 30; ++s)
        for(int i = 1; i <= n; ++i) 
            R[i][s] = R[R[i][s - 1]][s - 1];

    iota(a + 1, a + n + 1, 1);

    for(int s = 30; s >= 0; --s)
        if (d >> s & 1) 
            for(int i = 1; i <= n; ++i) a[i] = R[a[i]][s];

    for (int i = 1; i <= n; ++i) 
    cout << a[i] << " ";
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m24_d
