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

ll a, b;

int main() {
    nothing
    if (fopen("chuoi.inp", "r")) {
        freopen("chuoi.inp", "r", stdin);
        freopen("chuoi.out", "w", stdout);
    }
    cin >> a >> b;
    ll g = __gcd(a, b);
    
    cout << g;
    return 0;
}