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

ll n, a[maxn + 2], f[maxn + 2], ans = 0;;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    memset(f, -1, sizeof f);
    
    f[1] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j > 1; j--) {
            if (f[j - 1] >= 0) {
                f[j] = max(f[j], f[j - 1] + a[i]);
            } 
            if (f[j] >= 0) {
                ans = max(ans, 1LL * j);
            }
        }
    }
    cout << max(ans - 1, 1LL * 0);
    return 0;
}
