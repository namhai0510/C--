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
    if (fopen("nevaop6.inp", "r")) {
        freopen("nevaop6.inp", "r", stdin);
        freopen("nevaop6.out", "w", stdout);
    }
    ll a, b, c, d, e, ans = 0;
    
    cin >> a >> b >> c >> d >> e;
    ans += (int)(a >= b) + (int)(b >= a && b >= c) + (int)(c >= b && c >= d) + (int)(d >= c && d >= e) + (int)(e >= d);
    cout << ans;
    
    return 0;
}