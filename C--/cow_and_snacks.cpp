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

ll n, k;
vector<ll> adj[maxn + 2];

bool vis[maxn + 2];
ll res = 0, cnt = 0;

void Dfs(int u) {
	vis[u] = 1;
	res++;
	
	for (auto v : adj[u]) {
		if (!vis[v]) Dfs(v);
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    memset(vis, 0, sizeof(vis));
    cin >> n >> k;
    
    for (int i = 1; i <= k; ++i) {
    	ll u, v; cin >> u >> v;
    	
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    
    for (int i = 1; i <= n; ++i) {
    	if (!vis[i]) {
    		Dfs(i);
    		cnt += res - 1;
    		res = 0;
    	}
    }
    
    cout << k - cnt << endl;
    
    return 0;
}

// https://codeforces.com/problemset/problem/1209/D