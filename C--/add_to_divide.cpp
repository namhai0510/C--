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

ll a, b;
ll g, l;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> a >> b;
    
    g = __gcd(a, b);
    l = (a * b) / g;
    
    ll ans = l - a - b;
    while (ans < 0) ans += l;
    
    cout << ans << endl;
    return 0;
}

// tim x be nhat thoa man a + x chia het cho b va b + x chia het cho a
