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
const int maxn = 1e5;
const int maxa = 2e3;
const int base = 31;

ll n, q, l, k;
ll a[maxn + 2], res[30][maxn + 2];
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) cin >> a[i], res[0][i] = a[i];
    
    for (int i = 1; i <= 20; ++i)
    	for (int j = 1; j + (1 << i) - 1 <= n; ++j)
    		res[i][j] = max(res[i - 1][j], res[i - 1][j + (1 << (i - 1))]);
    
    while (q--) {
    	cin >> l >> k;
    	
    	cout << res[k - 1][l] << " " << res[k - 1][l + (1 << (k - 1))] << endl;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
