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

ll n, a[maxn + 2], mx[maxn + 2], res, pos;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = n; i >= 1; --i) mx[i] = max(a[i], mx[i + 1]);
    
    pos = 1;
    for (int i = 2; i <= n; ++i)
    	if (a[i] == mx[i] || a[i] > a[pos])
    		res += min(a[i], a[pos]) * (i - pos), pos = i;
    
    cout << res;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
