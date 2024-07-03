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

int n, k, a[maxn + 2], mn, ans;
int main() {
    nothing
    if (fopen("GCDMAX.inp", "r")) {
        freopen("GCDMAX.inp", "r", stdin);
        freopen("GCDMAX.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    
    mn = a[1];
    ans = 0;
    
    for (int j = mn; j >= 1; --j) {
        bool check = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] % j > k) {
                check = 0;
                break;
            }
        }
        
        if (check) {
            ans = j;
            break;
        }
    }
    cout << ans;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
