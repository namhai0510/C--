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
const int maxn = 1e6 + 5;
const int maxa = 6e2 + 5;
const int base = 31;

ll n, m, k, querry, cnt = 0, d[maxa + 2][maxa + 2];
ll x, y;

void Dfs(ll x, ll y, ll r) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	
	if (d[x][y] < r) {
		if (d[x][y] == -1) cnt++;
		d[x][y] = r; 
		
		Dfs(x - 1, y, r - 1);
		Dfs(x + 1, y, r - 1);
		Dfs(x, y - 1, r - 1);
		Dfs(x, y + 1, r - 1);
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> k >> querry;
    
    for (int i = 1; i <= n; ++i) 
    	for (int j = 1; j <= m; ++j) d[i][j] = -1;
    
    while (querry--) {
    	cin >> x >> y;
    	
    	Dfs(x, y, k);
    	
    	cout << cnt << endl;
    }
    return 0;
}
