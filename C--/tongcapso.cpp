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

ll n, q, a[maxn + 2];

ll CNT(ll x) {
    ll l = 1, r = n;
    ll cnt = 0;

    while (l < r) {
        if (a[l] + a[r] <= x) {
            cnt += (r - l);
            ++l;
        } else {
            --r;
        }
    }

    return cnt;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    
    cin >> q;
    while (q--) {
    	ll x; cin >> x;
    	cout << CNT(x) << endl;
    }
    return 0;
}
