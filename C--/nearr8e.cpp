#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, pos = 1;

int main() {
    nothing
    if (fopen("nearr8.inp", "r")) {
        freopen("nearr8.inp", "r", stdin);
        freopen("nearr8.out", "w", stdout);
    }
    cin >> m >> n;
    ll a[m + 2][n + 2];
    // (i - 1) * n + j
    pos = 1;
    for (int i = 1; i <= (m + 1) / 2; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		a[i][j] = pos;
    		if (i != m - i + 1) 
    			a[m - i + 1][j] = pos + n;
    		pos++;
    	}
    	pos += n;
    }
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) cout << a[i][j] << " ";
    	cout << endl;
    }
    return 0;
}
