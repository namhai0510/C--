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

ll m, n, q, a[maxa + 2][maxa + 2], res = 0;
ll sum[4][maxa + 2][maxa + 2];

void Subtask() {
	for (int test = 1; test <= q; ++test) {
    	ll x, y, k;
    	cin >> x >> y >> k;
    	
    	res = 0;
    	for (int i = 0; i < k; ++i) res += a[x + i][y + i];
    	for (int i = 0; i < k; ++i) res += a[x + i][y + k - i - 1];
    	
    	if (k % 2 == 1) res -= a[x + k / 2][y + k / 2];
    	cout << res << endl;
    } 
    
    exit(0);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n >> q;
    
    for (int i = 1; i <= m; ++i) 
    	for (int j = 1; j <= n; ++j) cin >> a[i][j];
    	
    if (q <= 2000) Subtask();
    
    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= n; ++j) {
    		sum[1][i][j] = sum[1][i - 1][j - 1] + a[i][j];
    		sum[2][i][j] = sum[2][i - 1][j + 1] + a[i][j];
    	}
    	
    for (int test = 1; test <= q; ++test) {
    	ll x, y, k;
    	cin >> x >> y >> k;
    	
    	res = sum[1][x + k - 1][y + k - 1] - sum[1][x - 1][y - 1] + sum[2][x + k - 1][y] - sum[2][x - 1][y + k];
    	if (k % 2 == 1) res -= a[x + k / 2][y + k / 2];
    	
    	cout << res << endl;
    }
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
