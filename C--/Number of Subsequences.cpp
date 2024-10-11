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
const int maxn = 2e5;
const int maxa = 2e3;
const int base = 31;

ll n;
string s;
ll cQ = 0, res = 0;
ll p3[maxn + 2], dp[maxn + 2][5][5];

void Process() {
	for (int i = 0; i < n; ++i) 
		if (s[i] == '?') cQ++;
		
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= 3; ++j)
			for (int k = 0; k <= 3; ++k) {
			 	if (!dp[i][j][k]) continue;
			 	
			 	dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k] + mod) % mod;
			 	
			 	if (j < 3 && (s[i] == '?' || s[i] - 'a' == j)) {
			 	 	int tmp = (s[i] == '?' ? k + 1 : k);
			 	 	dp[i + 1][j + 1][tmp] = (dp[i + 1][j + 1][tmp] +  dp[i][j][k] + mod) % mod;
			 	}
		   	}
		   	
	for (int i = 0; i <= 3; ++i)
		if (cQ >= i)
			res = (res + (dp[n][3][i] * p3[cQ - i]) % mod + mod) % mod;
			
	cout << res % mod << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    p3[0] = 1;
	for (int i = 1; i <= maxn; ++i) 
		p3[i] = ((p3[i - 1] % mod) * 3LL) % mod;
		
    cin >> n;
    cin >> s;
    
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1426/F
