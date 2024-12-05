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

ll n, a[maxn + 2], res = 0;

int main() {
    nothing
    if (fopen("MINNUM.inp", "r")) {
        freopen("MINNUM.inp", "r", stdin);
        freopen("MINNUM.out", "w", stdout);
    }
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i) {
        if (a[i] > res + 1){
            break;
        }
        else {
            res += a[i];
        }
    }
    
    cout << res + 1;
	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
