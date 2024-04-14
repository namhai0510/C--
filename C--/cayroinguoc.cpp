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

ll t, n, q, d[maxn + 2], deg[maxn + 2];
vector<ll> adj[maxn + 2];
bool vis[maxn + 2];

void Dfs(ll s) {
	vis[s] = 1;
	
	for (auto e : adj[s]) {
		if (vis[e] == 0) {
			Dfs(e);
			d[s] += d[e];
		}
	}
	
	if (d[s] == 0) d[s] = 1;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		vis[i] = 0;
    		d[i] = 0;
    		adj[i].clear();
    	}
    	
    	for (int i = 1; i <= n - 1; ++i) {
    		ll u, v;
    		cin >> u >> v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    		
    		deg[u]++;
    		deg[v]++;
    	}
    	
    	Dfs(1);
    	
    	// for (int i = 1; i <= n; ++i) cout << d[i] << " ";
    	
    	cin >> q;
    	while (q--) {
    		ll x, y;
    		cin >> x >> y;
    		cout << d[x] * d[y] << endl;
    	}
    	
    }
    return 0;
}
