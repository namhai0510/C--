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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, a[maxn + 2], f[maxn + 2];
int main() {
    nothing
    if (fopen("cable.inp", "r")) {
        freopen("cable.inp", "r", stdin);
        freopen("cable.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n - 1; ++i) cin >> a[i];
    
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	f[i] = +oo;
    	if (i > 1) f[i] = min(f[i], f[i - 2] + a[i - 1]);
    	if (i > 2) f[i] = min(f[i], f[i - 3] + a[i - 1] + a[i - 2]);
    }
    
    cout << f[n] << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
