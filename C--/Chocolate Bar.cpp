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

ll t, n, m, k;
ll dp[40][40][60];

void Init() {
	for (int i = 1; i <= 30; ++i) {
		for (int j = 1; j <= 30; ++j) {
			dp[i][j][0] = 0;
			
			for (int k = 1; k <= 50; ++k) {
				if (k == i * j) dp[i][j][k] = 0;
				else {
					dp[i][j][k] = +oo;
					
					for (int t = 0; t <= k; ++t) {
	                    for (int h = 1; h < i; ++h)
	                        dp[i][j][k] = min(dp[i][j][k], j * j + dp[h][j][t] + dp[i - h][j][k - t]);

	                    for (int h = 1; h < j; ++h)
	                        dp[i][j][k] = min(dp[i][j][k], i * i + dp[i][h][t] + dp[i][j - h][k - t]); 
	                }
				}
			}
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Init();
    
    cin >> t;
    
    while (t--) {
    	cin >> n >> m >> k;
    	
    	cout << dp[n][m][k] << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/598/E