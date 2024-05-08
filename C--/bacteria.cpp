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

ll n, m, a[maxa + 2][maxa + 2], b[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> b[i][j];
    	}
    }
    
	ll layer = min(m, n) + 1;
	layer /= 2;
	
	// cout << layer << endl;
	
	for (int l = 1; l <= layer; ++l) {
		int row[] = {n - l * 2 + 1, n - l}, col[] = {m - l * 2 + 1, m - l};
		
		for (int i = 0; i < row[0]; ++i) {
			ll x = i + l;
            a[x][l] = b[x][l - 1];
            a[x][col[1]] = b[x][col[1] + 1];
		}
		
		for (int j = 0; j < col[0]; ++j) {
			ll y = j + l;
			a[l][y] = b[l - 1][y];
			a[row[1]][y] = b[row[1] + 1][y];
		}
		
		for (int i = 0; i < row[0]; i++) {
            ll x = i + l;
            b[x][l] -= a[x - 1][l] + a[x + 1][l] + a[x][l - 1];
            b[x][col[1]] -= a[x - 1][col[1]] + a[x + 1][col[1]] + a[x][col[1] + 1];
        }
        for (int j = 0; j < col[0]; j++) {
            int y = j + l;
            b[l][y] -= a[l][y - 1] + a[l][y + 1] + a[l - 1][y];
            b[row[1]][y] -= a[row[1]][y - 1] + a[row[1]][y + 1] + a[row[1] + 1][y];
        }
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cout << a[i][j] << " ";
		cout << endl;
	}
    return 0;
}

// https://oj.vnoi.info/problem/bedao_g15_a
