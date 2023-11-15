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
    if (fopen("nevaop4.inp", "r")) {
        freopen("nevaop4.inp", "r", stdin);
        freopen("nevaop4.out", "w", stdout);
    }
    ll x; 
    cin >> x;
    
    ll dif = x % 2;
    cout << (x / 2) * 2 << endl << (x / 2 + dif) * 2 << endl;
    cout << (x / 2 + dif) * 2 - 1 << endl << (x / 2 + dif) * 2 + 1 << endl;
    
    return 0;
}