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

const string aim = "narek";
ll test;
ll n, m;
string s[maxa + 2];
ll dp[5], cur[5], cnt, nxt, res = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
	cin >> test;
	
	while (test--) {
		cin >> n >> m;
		
		for (int i = 1; i <= n; ++i) cin >> s[i];
		
		dp[0] = 0;
		dp[1] = dp[2] = dp[3] = dp[4] = -oo;
		
		for (int i = 1; i <= n; ++i) {
			for (int x = 0; x <= 4; ++x) cur[x] = dp[x];
			
			for (int x = 0; x <= 4; ++x) {
				if (dp[x] == -oo) continue;
				
				cnt = 0;
				nxt = x;
				
				for (int k = 0; k < m; ++k) {
					int pos = aim.find(s[i][k]);
					
					if (pos == -1) continue;
					
					if (nxt == pos) {
						nxt++;
						nxt %= 5;
						cnt++;
					}
					else cnt--;
				}
				
				cur[nxt] = max(cur[nxt], dp[x] + cnt);
			}
			
			for (int x = 0; x <= 4; ++x) dp[x] = cur[x];
		}
		
		res = 0;
		for (int i = 0; i <= 4; ++i)
			res = max(res, dp[i] - 2 * i);
			
		cout << res << endl;
		
	}
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/2005/C
