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

ll n, a[maxn + 2], res, b[5];

int main() {
    nothing
    if (fopen("CB.inp", "r")) {
        freopen("CB.inp", "r", stdin);
        freopen("CB.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[0] = 1;
        for (int j = 3; j >= 0; j--) {
            if (b[j] == 1) {
                if (j + a[i] > 3) {
                    res++;
                    b[j] = 0;
                } else {
                    b[j + a[i]] = 1;
                }
            }
        }
    }
    cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
