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
const int maxn = 1e5;
const int maxa = 2e3;
const int base = 31;

ll test;
ll m, x, money;
ll c[maxn + 2], h[maxn + 2];
ll dp[60][maxn + 2], ps[maxn + 2];

void Input() {
	cin >> m >> x;
	
	ps[0] = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> c[i] >> h[i];
		
		ps[i] = ps[i - 1] + h[i];
	}
}

void Process() {
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= ps[m]; ++j) dp[i][j] = +oo;
	dp[0][0] = 0;
	
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= ps[i]; ++j) dp[i][j] = dp[i - 1][j];
		
		money = (i - 1) * x;
		
		for (int j = h[i]; j <= ps[i]; ++j)
			if (dp[i - 1][j - h[i]] + c[i] <= money)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - h[i]] + c[i]);
	}
	
	money = (m - 1) * x;
	
	for (int i = ps[m]; i >= 0; --i)
		if (dp[m][i] <= money) {
			cout << i << endl;
			return;
		}
	
	cout << 0 << endl;
	return;
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

// https://codeforces.com/problemset/problem/1974/E
