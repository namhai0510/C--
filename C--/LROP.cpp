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

ll n, a[maxn + 2], b[maxn + 2], sum, res, ans = -oo;
ll p1[maxn + 2], p2[maxn + 2], p3[maxa + 2][maxa + 2];
int main() {
    nothing
    if (fopen("LROP.inp", "r")) {
        freopen("LROP.inp", "r", stdin);
        freopen("LROP.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= n; ++j) cin >> b[j];
    
    for (int i = 1; i <= n; ++i) p1[i] = p1[i + 1] + a[i] * b[i];
    for (int i = 1; i <= n; ++i) p2[i] = p2[i - 1] + a[i] * b[i];
    
    for (int i = 1; i <= n; ++i){
        p3[i][i + 1] = 2 * b[i] * b[i + 1];
    	for (int r = 1; r < min(i + 0LL, n - i); ++r)
            p3[i - r][i + r + 1] = p3[i - r + 1][i + r] + 2 * b[i - r] * b[i + r + 1];
    }

    for (int i = 1; i <= n; ++i)
        for (int r = i; r <= n; ++r)
            ans = max(ans, 2 * p2[i - 1] + p1[r + 1] - p2[r] + p3[i][r]);
            
    cout << ans;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
