#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll test;
ll n, dp[maxn + 2][5];
pair<ll, ll> fence[maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> fence[i].fi >> fence[i].se;
	
	dp[1][0] = 0;
	dp[1][1] = fence[1].se;
	dp[1][2] = fence[1].se * 2;
}

void Process() {
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 2; ++j) {
			dp[i][j] = +oo;
			
			for (int k = 0; k <= 2; ++k) {
				if (fence[i].fi + j != fence[i - 1].fi + k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + fence[i].se * j);
			}
		}
	}	
	
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1221/D
