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

string s;
ll n, res = 0;
ll dp[maxn + 2], alphabet[26];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> s;
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) dp[i] = 1;
    
    for (int i = 1; i <= n; ++i) {
		for (int c = 25; c > s[i] - 'a'; --c)
			dp[i] = max(dp[i], alphabet[c] + 1);
		
		alphabet[s[i] - 'a'] =  max(alphabet[s[i] - 'a'], dp[i]);
	}
	
	for (int i = 0; i <= 25; ++i) res = max(res, alphabet[i]);
	
	cout << res << endl;
	for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1296/E2