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

const ll inf = 1e17;

ll n, q, a[maxn], val[maxn], vt[maxn], ps[maxn], bit[maxn], bit1[maxn], f[maxn];
vector<ll> v;
vector<ll> del, del1;

void upd(ll pos, ll val) {
    for (; pos <= n + 1; pos += pos & (-pos)) {
        bit[pos] = max(bit[pos], val);
        del.pb(pos);
    }
}

ll get(ll pos) {
    ll res = -1;
    for (; pos > 0; pos -= pos & (-pos)) res = max(res, bit[pos]);
    return res;
}

void upd1(ll pos, ll val) {
    for (; pos > 0; pos -= pos & (-pos)) {
        bit1[pos] = max(bit1[pos], val);
        del1.pb(pos);
    }
}

ll get1(ll pos) {
    ll res = -1;
    if (pos == 0) return -1;
    for (; pos <= n + 1; pos += pos & (-pos)) res = max(res, bit1[pos]);
    return res;
}

void Process() {
    for (ll i = 1; i <= n + 1; i++) bit[i] = bit1[i] = -1;
    while (q--) {
        ll l, r; cin >> l >> r;
        for (ll j = 1; j <= r; j++) {
            ll cnt = 0;
            for (ll ii = j; ii >= l; ii--) {
                if (val[ii] == 1) cnt++;
                if (cnt >= 2) break;
                if (cnt >= 1) {
                    if (ps[j] >= ps[ii - 1]) f[j] = max(f[j], f[ii - 1] + 1);
                    else f[j] = max(f[j], f[ii - 1]);
                }
            }
        }
        cout << f[r] << '\n';
        for (ll i = l; i <= r; i++) f[i] = 0;
    }
}

void Input() {
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        char c;
        cin >> c;
        val[i] = c - '0';
    }
    v.pb(0);
    v.pb(-inf);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
        v.pb(ps[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll i = 0; i <= n; i++) {
        ps[i] = lower_bound(v.begin(), v.end(), ps[i]) - v.begin();
    }
}

int main() {
    nothing
    if (fopen("QSNAIL.inp", "r")) {
        freopen("QSNAIL.inp", "r", stdin);
        freopen("QSNAIL.out", "w", stdout);
    }

    Input();
    Process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}