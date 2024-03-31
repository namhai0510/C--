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

ll n, m, k;
char a[maxa + 2][maxa + 2];
ll vis[maxa + 2][maxa + 2];
ll num[maxn + 2], ans = 0, it;

void Visit(ll x,ll y) {
	if (x < 1 || y < 1 || x > m || y > n) return;
	
	if (a[x][y] == '*') {
		ans++;
		return;
	}
	
	if (vis[x][y] !=0) return;
	vis[x][y] = it;
	
	Visit(x + 1, y);
	Visit(x, y + 1);
	Visit(x - 1, y);
	Visit(x, y - 1);
	
	return;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n >> k;
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    for (int i = 1; i <= k; ++i) {
    	ll x, y; cin >> x >> y;
    	ans = 0;
    	it = i;
    	
    	if (!vis[x][y]) Visit(x, y);
    	else ans = num[vis[x][y]];
    	
    	num[i] = ans;
    	
    	cout << ans << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/598/D