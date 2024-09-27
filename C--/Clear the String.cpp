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
const int maxa = 5e2;
const int base = 31;

ll n, dp[maxa + 2][maxa + 2];
string s;

void Init() {
	for (int i = 0; i <= maxa; ++i)
		for (int j = 0; j <= maxa; ++j) dp[i][j] = +oo;
		
	for (int i = 1; i <= n; ++i) dp[i][i] = 1;
}

void Process() {
	for (int l = n; l >= 1; --l) {
		for (int r = l + 1; r <= n; ++r) {
			for (int i = l; i < r; ++i)
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
			
			if (s[l] == s[r]) dp[l][r]--;
		}
	}
	
	cout << dp[1][n] << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    cin >> s;
    s = '#' + s;
    
    Init();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1132/F
