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
const int maxn = 1e7 + 1;
const int maxa = 2e3;
const int base = 31;

int f[maxn + 2], n, res = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    cin >> n;
    
    for (int i = 1; i <= n; ++i) f[i] = 1;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 4) ++res;
        for (int j = i * 2; j <= n; j += i) ++f[j];
    }
    cout << res;
    

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
