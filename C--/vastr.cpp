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
const int maxa = 5e3;
const int base = 31;

ll n, res = 0;
string s;
bool pal[maxa + 2][maxa + 2];
ll dp[maxa + 2][maxa + 2], c[3][maxa + 2][maxa + 2];
// dp[i][j] : num of l that s[i - l + 1...i] == s[j...j + l - 1];
// c[1][i][j] : num of u that pal[s[i...u]] == 1;
// c[2][i][j] : num of u that pal[s[u...j]] == 1;

int main() {
    nothing
    if (fopen("vastr.inp", "r")) {
        freopen("vastr.inp", "r", stdin);
        freopen("vastr.out", "w", stdout);
    }
    
    cin >> n;
    cin >> s;
    
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) pal[i][i] = 1;
    for (int i = 1; i < n; ++i) 
    	if (s[i] == s[i + 1]) pal[i][i + 1] = 1;
    for (int i = n; i >= 1; --i) 
    	for (int j = i + 2; j <= n; ++j)
    		if (s[i] == s[j] && pal[i + 1][j - 1]) pal[i][j] = 1;
    // pal[i][j] == 1 : s[i..j] is palindrome.
    
    for (int i = 1; i <= n; ++i)
    	for (int j = i + 1; j <= n; ++j) 
    		if (s[i] == s[j]) dp[i][j] = 1;
	
	for (int i = 1; i <= n; ++i) 
		for (int j = n; j > i; --j) 
			if (s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
			else dp[i][j] = 0;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j)
    		c[1][i][j] = c[1][i][j - 1] + (pal[i][j] ? 1 : 0);
    	
    	for (int j = i; j >= 1; --j)
    		c[2][j][i] = c[2][j + 1][i] + (pal[j][i] ? 1 : 0);
    }
    		
    for (int i = 1; i <= n; ++i)
    	for (int j = i; j <= n; ++j)
    		res += dp[i][j] + dp[i - 1][j + 1] * (c[1][i][j] + c[2][i][j]);
    		
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
