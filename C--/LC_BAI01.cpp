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
const ll mod = 1e9;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll a, b, n, m;
ll product (ll a, ll b, ll m) {
    if (b == 0) return 0;
    ll t = product(a, b / 2, m);      
    t = (t + t) % m; 
    if (b % 2 == 1) 
        t = (t + a) % m;
    return t;
} 

ll power(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll t = power(a, b / 2, m);         
    t = (product(t, t, m)) % m; 
    if (b % 2 == 1) 
        t = (product(t, a, m)) % m;
    return t;
} 

int main() {
    nothing
    if (fopen("LC_BAI01.inp", "r")) {
        freopen("LC_BAI01.inp", "r", stdin);
        freopen("LC_BAI01.out", "w", stdout);
    }
    cin >> a >> b >> n >> m;
    cout << power(a, n, mod) + power(b, m, mod) << endl;
    return 0;
}