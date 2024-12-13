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
const int maxa = 3e2;
const int base = 31;

int m, n, k, num;
ll a[maxa + 2], b[maxa + 2];
set<pair<ll, pair<ll, ll>>> st;

pair<ll, ll> Minimalist(pair<ll, ll> x) {
    ll y = (x.fi * x.se < 0) ? -1 : 1;
    ll g = __gcd(abs(x.fi), abs(x.se));
    return {abs(x.fi / g) * y, abs(x.se / g)};
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> m >> n >> k;
    
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            st.insert({a[i] * 100000 / b[j], Minimalist({a[i], b[j]})});
        }
    }

    num = 1;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (num == k) {
            cout << it->se.fi << " " << it->se.se;
            return 0;
        }
        num++;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
