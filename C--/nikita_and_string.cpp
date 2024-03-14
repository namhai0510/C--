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

string s;
ll n, pre[5][maxn + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    
    n = s.size();
    s = '#' + s;
    
    pre[1][0] = pre[2][0] = 0;
    for (int i = 1; i <= n; ++i) {
    	pre[1][i] = pre[1][i - 1];
    	pre[2][i] = pre[2][i - 1];
    	
    	if (s[i] == 'a') pre[1][i]++;
    	if (s[i] == 'b') pre[2][i]++;
    }
    
    if (n == 1) {
    	cout << 1;
    	return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = i + 1; j <= n; ++j) {
    		ans = max(ans, (pre[1][n] - pre[1][j - 1]) + (pre[2][j] - pre[2][i - 1]) + pre[1][i]);
    	}
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/877/B