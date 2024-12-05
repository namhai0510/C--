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
const int maxa = 5e2;
const int base = 31;

ll n, k, r, res = 0;
ll a[maxa + 2][maxa + 2], ps[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("POURBOI.inp", "r")) {
        freopen("POURBOI.inp", "r", stdin);
        freopen("POURBOI.out", "w", stdout);
    }
    
    cin >> n >> r >> k;
    
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= n; ++j) cin >> a[i][j];
    	
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		
		for (int j=y;j<=min(y+r-1,n);++j){
			ps[x][j]++;
			ps[min(x + r - 1, n) + 1][j]--;
		}
	}
	
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			ps[i][j] += ps[i - 1][j];
			if (ps[i][j] > 0) res += a[i][j];
		}
	}
	
	cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
