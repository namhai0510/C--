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

ll n, m, d;

void Sub1() {
	ll f[n + 2][m + 2];
	
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; ++i) {
		f[i][i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j > i) break;
			
			for (int k = 1; k <= m; ++k) {
				if (abs(j - k) <= d) {
					f[i][j] += f[i - j][k];
					f[i][j] %= modd;
				}
			}
		}
	}
	
	// for (int i = 1; i <= n; ++i) {
		// for (int j = 1; j <= m; ++j) cout << f[i][j] << " ";
		// cout << endl;
	// }
	
	ll ans = 0;
	for (int j = 1; j <= m; ++j) {
		ans += f[n][j];
		ans %= modd;
	}
	cout << ans << endl;
}

void Sub2() {
	ll f[maxn + 2][4];
}

void Sub3() {
	
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> d;
    
    if (n <= 100000) Sub1();
    else if (m == 2) Sub2();
    else Sub3();
    
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m22_e