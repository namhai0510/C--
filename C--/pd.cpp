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
const int maxa = 3e4 + 5;
ull a, b, c, d, e, f;

int main() {
    nothing
    if (fopen("pd.inp","r")) {
        freopen("pd.inp","r",stdin);
        freopen("pd.out","w",stdout);
    }
    cin >> a >> b >> c >> d >> e >> f;

    a %= mod; b %= mod; c %= mod; d %= mod; e %= mod; f %= mod;
    cout << ((((a * b) % mod) * c) % mod + mod - (((d * e) % mod) * f) % mod) % mod;
}

