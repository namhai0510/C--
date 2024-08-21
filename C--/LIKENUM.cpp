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

ll x, n, sx, sn, z = 0, kq = 0;

ll cnt_num(ll num) {
    ll dem = 0;
    while (num > 0) {
        dem++;
        num /= 10;
    }
    return dem;
}

ll power(ll base, ll p) {
    ll dem = 1;
    for (int i = 1; i <= p; i++) {
        dem *= base;
    }
    return dem;
}

void Input() {
    cin >> x >> n;
    sx = cnt_num(x);
    sn = cnt_num(n);
    if (x <= n % power(10, sx)) z = 1;
}

void Process() {
    kq = n / power(10, sx) - 1 + z;
    cout << kq;
}

int main() {
    nothing
    if (fopen("LIKENUM.inp", "r")) {
        freopen("LIKENUM.inp", "r", stdin);
        freopen("LIKENUM.out", "w", stdout);
    }

    Input();
    Process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
