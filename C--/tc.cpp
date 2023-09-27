#include<bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL);
using ll = long long;
using ull = unsigned long long;
#define in insert
#define fi first
#define se second
#define pb push_back
#define el "\n"
const ll mod = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 5e3 + 8;
ll r, c, d, k;
ll ans = 0;
char a[maxa + 2][maxa + 2];
char a2[maxn + 5];
ll tree[maxn + 5];

ll dis(ll x, ll y, ll z, ll t) {
    return max(abs(x - z), abs(y - t));
}

void Sub4() {
    vector<pair<ll, ll>> tr, w;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'M') tr.pb({i, j});
            else if (a[i][j] == 'S') w.pb({i, j});
        }
    }

    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j < tr.size(); ++j) {
            if (d >= dis(w[i].fi, w[i].se, tr[j].fi, tr[j].se)) tree[j]++;
        }
    }

    for (int i = 0; i < tr.size(); ++i) {
        if (k <= tree[i]) ans++;
    }

    cout << ans;
}

void Sub5() {
    vector<ll> w;
    for (int i = 1; i <= c; ++i) {
        if (a2[i] == 'S') w.pb(i);
    }

    for (int i = 0; i < w.size(); ++i) {
        for (int j = w[i] - 1; j >= w[i] - d; --j) {
            if (j == 0) break;
            if (a2[j] == 'M') tree[j]++;
        }
        for (int j = w[i] + 1; j <= w[i] + d; ++j) {
            if (j > c) break;
            if (a2[j] == 'M') tree[j]++;
        }
    }

    for (int i = 1; i <= c; ++i) {
        if (k >= tree[i]) ans++;
    }

    cout << ans;
}

ll f[maxn + 5];
void Sub6() {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (a[i][j] == 'M') f[i] += d;
            else if (a[i][j] == 'S') f[i] += k;
        }
    }

    for (int i = 1; i <= c; ++i) {
        ans = max(ans, f[i]);
    }

    cout << ans;
}
int main() {
    nothing
    if (fopen("tc.inp","r")) {
        freopen("tc.inp","r",stdin);
        freopen("tc.out","w",stdout);
    }
    cin >> r >> c >> d >> k;
    if (r <= 505 && c <= 505) Sub4();
    else if (r == 1) Sub5();
    else Sub6();
    return 0;
}

