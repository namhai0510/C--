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

ll n, m, res = 1, pos = 1;

int main() {
    nothing
    if (fopen("nearr8.inp", "r")) {
        freopen("nearr8.inp", "r", stdin);
        freopen("nearr8.out", "w", stdout);
    }
    cin >> n; m = n;
    ll a[n + 2][m + 2];
    
    ll pre = m;
    for (int j = n; j >= 1; --j) {
    	int i = pre;
    	while (i > 0 && i < m + 1) {
    		a[j][i] = pos;
    		pos++;
    		if (pre == 1) i++;
    		else i--;
    	}
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) cout << a[i][j] << " ";
    	cout << endl;
    }
    return 0;
}
