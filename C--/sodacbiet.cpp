#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

vector<ll> a;

int main() {
    nothing
    if (fopen("xephang.inp", "r")) {
        freopen("xephang.inp", "r", stdin);
        freopen("xephang.out", "w", stdout);
    }
	ll l, r;
    cin >> l >> r;

	a.resize(r + 1, 1);
    for (ll i = 2; i <= r / 2; i++) {
        for (ll j = 2; j <= r / i; j++) {
            a[i * j] += i;
        }
    }
    
    ll res = 0;
    for (ll  i = l; i <= r; i++) {
        if (a[i] > i) {
            res++;
        }
    }
    cout << res << endl;
    
    return 0;
}
