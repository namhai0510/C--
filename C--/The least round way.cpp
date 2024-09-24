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
const int maxa = 1e3;
const int base = 31;

ll n, a[maxa + 2][maxa + 2];
ll dp[2][maxa + 2][maxa + 2], f[2][maxa + 2][maxa + 2], x, y, ans;
char c[2][maxa + 2][maxa + 2];
bool ex = 0;

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			
			if (!a[i][j]) {
				x = i, y = j;
				ex = 1;
				continue;
			}
			
			while (a[i][j] % 2 == 0) {
				a[i][j] /= 2;
				f[0][i][j]++;
			}
			while (a[i][j] % 5 == 0) {
				a[i][j] /= 5;
				f[1][i][j]++;
			}
		}
	}
}

void Process() {
	dp[0][n][n] = f[0][n][n];
	dp[1][n][n] = f[1][n][n];
	
	for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            for (int k = 0; k < 2; ++k) {
                if (i == n && j == n) continue;
                
                if (i < n) {
                    dp[k][i][j] = dp[k][i + 1][j] + f[k][i][j];
                    c[k][i][j] = 'D';
                }
                
                if (i == n || (j < n && dp[k][i][j] > dp[k][i][j + 1] + f[k][i][j])) {
                    dp[k][i][j] = dp[k][i][j + 1] + f[k][i][j];
                    c[k][i][j] = 'R';
                }
            }
        }
    }

    ans = min(dp[0][1][1], dp[1][1][1]);
    
    if (ex && ans > 0) {
        cout << 1 << '\n';
        
        for (int i = 1; i <= y; ++i) cout << 'R';
        for (int i = 1; i <= x; ++i) cout << 'D';
        for (int i = 1; i <= n - y - 1; ++i) cout << 'R';
        for (int i = 1; i <= n - x - 1; ++i) cout << 'D';
        return;
    }

    cout << ans << '\n';

    int i = 1, j = 1, k;
    k = (dp[0][1][1] < dp[1][1][1] ? 0 : 1);
    
    while (i != n || j != n) {
        cout << c[k][i][j];
        
        if (c[k][i][j] == 'D') ++i;
        else ++j;
    }
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/2/B