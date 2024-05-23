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

ll n, test, a[maxn + 2], pfx[10][maxn + 2], res;

ll Calc (ll val) {
    ll tmp = 1;
    while (val > 0) {
        if (val % 10 != 0) tmp *= (val % 10);
        val /= 10;
    }
    
    return tmp;
}

void Init() {
    for(int i = 1; i <= maxn; ++i) {
    	for (int j = 1; j <= 9; ++j)
    		pfx[j][i] = pfx[j][i - 1];

        ll x = i;
        
        while (1) {
            x = Calc(x);
            if (x <= 9) break;
        }
        
        pfx[x][i]++;
    }
}
int main() {
    nothing
    if (fopen("digitx.inp", "r")) {
        freopen("digitx.inp", "r", stdin);
        freopen("digitx.out", "w", stdout);
    }
    Init();
    
    cin >> test;
    
    while (test--) {
    	ll l, r, k;
        cin >> l >> r >> k;
        cout << pfx[k][r] - pfx[k][l - 1] << endl;
    }
    
    return 0;
}
