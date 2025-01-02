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

ll n, m, a[maxn], res = +oo;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
     nothing
    if (fopen("TONGNN.inp", "r")) {
        freopen("TONGNN.inp", "r", stdin);
        freopen("TONGNN.out", "w", stdout);
    }
    cin >> n >> m;
    
    if (m % n != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int k = 1; k <= m / n; k++) {
        if ((m / n) % k == 0) {
            ll a = n * k;
            ll b = m / k;
            if (__gcd(a, b) == n && lcm(a, b) == m) {
                res = min(res, a + b);
            }
        }
    }
    
    if (res == oo) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
