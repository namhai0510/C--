#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll m, n, res = 0;
pair<ll, ll> a[maxa + 2], b[maxa + 2];

int main() {
    nothing
    if (fopen("PIN.inp", "r")) {
        freopen("PIN.inp", "r", stdin);
        freopen("PIN.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
    }
    
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((a[i].fi < b[j].fi && a[i].se < b[j].se) && (a[j].fi < b[i].fi && a[j].se < b[i].se)) res++;
        }
    }
    cout << res;
    return 0;
}
