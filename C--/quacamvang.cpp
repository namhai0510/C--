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

struct type {
    ll pos;
    ll cam;
};

vector<type> v;

bool cmp(type x, type y) {
    return x.pos < y.pos;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    ll n, k, h;
    cin >> n >> k >> h;
    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        ll pos = i * k;
        v.pb({pos - h, a});
        v.pb({pos + h + 1, -a});
    }

    sort(v.begin(), v.end(), cmp);

    ll res = 0, cur = 0;
    for (auto &p : v) {
        cur += p.cam;
        res = max(res, cur);
    }

    cout << res << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
