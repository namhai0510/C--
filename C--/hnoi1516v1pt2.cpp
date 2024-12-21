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
const int maxn = 5e4;
const int maxa = 2e3;
const int base = 31;

ll n, m, a[maxn + 2];
pair<ll, ll> b[maxn];
ll mn, res, l, r, mid, tmp = 0;

bool cmp(pair<ll, ll> A, pair<ll, ll> B) {
    return (A.fi < B.fi) || (A.fi == B.fi && A.se >= B.se);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i].fi >> b[i].se;
    sort(b + 1, b + 1 + m, cmp);
    
    mn = b[m].se;
    for (int i = m - 1; i >= 1; --i) {
        mn = min(mn, b[i].se);
        b[i].se = mn;
    }

    res = 0;
    for (int i = 1; i <= n; ++i) {
    	l = 1, r = m, tmp = 0;
    	
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[i] <= b[mid].fi) {
                tmp = b[mid].se;
                r = mid - 1;
            } else l = mid + 1;
        }
        res += tmp;
    }

    cout << res << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
