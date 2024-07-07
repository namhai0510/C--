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
const int maxa = 2e3 + 5;
const int base = 31;
const ll drt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

ll test, n, m;
char a[150][150];
bool vis[150][150];

bool Inside(int x, int y) {
	return ((x >= 1 && x <= n) && (y >= 1 && y <= m));
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n >> m;
    	
    	for (int i = 1; i <= n; ++i) 
    		for (int j = 1; j <= m; ++j) cin >> a[i][j];
    		
    	for (int i = 1; i <= n; ++i) 
    		for (int j = 1; j <= m; ++j) 
    			if (a[i][j] == 'B') 
    				for (int x = 0; x < 4; ++x) {
    					int ii = i + drt[x][0], jj = j + drt[x][1];
    					if (Inside(ii, jj) && a[ii][jj] == '.')
    						a[ii][jj] = '#';
    				}
    	
    	memset(vis, 0, sizeof(vis));
    	queue<pair<ll,ll>> q;
    	
    	if (a[n][m] == '.') {
    		q.push({n, m});
    		vis[n][m] = 1;
    	}
    	
    	while (!q.empty()) {
    		pair<ll, ll> v = q.front();
    		q.pop();
    		
    		for (int x = 0; x < 4; ++x) {
    			int ii = v.fi + drt[x][0], jj = v.se + drt[x][1];
    			if (Inside(ii, jj) && !vis[ii][jj] && a[ii][jj] != '#') {
	    			q.push({ii, jj});
	    			vis[ii][jj] = 1;
    			}
    		}	
    	}
    	
    	bool exist = 1;
    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j) 
    			if ((a[i][j] == 'G' && !vis[i][j])
    				|| (a[i][j] == 'B' && vis[i][j])) {
    					exist = 0;
    					break;
    				}
    				
    	if (exist) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1365/D