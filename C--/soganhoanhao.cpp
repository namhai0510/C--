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

const int maxN = 1e3 + 5;

ll sum_uoc(ll num) {
    ll sum = 0;
    for (ll i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (i == (num / i)) {
                sum += i;
            } else {
                sum += (i + num / i);
            }
        }
    }
    return (sum + 1);
}

bool check(ll n) {
    return sum_uoc(n) + n >= 2 * n;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    ll k;
    cin >> k;
    for (ll i = 1; i <= k; i++) {
        ll a;
        cin >> a;
        if (check(a)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
