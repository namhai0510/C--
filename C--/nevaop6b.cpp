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

int main() {
    nothing
    if (fopen("nevaop6b.inp", "r")) {
        freopen("nevaop6b.inp", "r", stdin);
        freopen("nevaop6b.out", "w", stdout);
    }
    ll a, b, c, d, e, f, g, h, i;
    ll ans = 0;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    
    ans += (3 * a >= (b + d + e)) + 
    (5 * b >= (a + c + d + e + f)) + 
    (3 * c >= (b + e + f)) + 
    (5 * d >= (a + b + e + g + h)) + 
    (8 * e >= (a + b + c + d + f + g + h + i)) + 
    (5 * f >= (b + c + e + h + i)) + 
    (3 * g >= (d + e + h)) + 
    (5 * h >= (d + e + f + g + i)) + 
    (3 * i >= (e + f + h));
    cout << ans << endl;
}