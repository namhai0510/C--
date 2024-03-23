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

ll n, m;
vector<pair<ll, ll>> adj[maxn + 2];
ll vis[maxn + 2], trace[maxn + 2], D[maxn + 2];
vector<ll> path;

bool fp = 1;

void Pre(int n) {
	for (int i = 1; i <= n; ++i) {
		vis[i] = 0;
		trace[i] = -1;
		D[i] = +oo;
	}
}

void Dijkstra(int st, int en) {
	D[st] = 0;
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> h;
	h.push({D[st], st});
	
	while (!h.empty()) {
		pair<ll, ll> x = h.top();
		h.pop();
		
		int u = x.se;
		
		if (vis[u] == 1) continue;
		
		vis[u] = 1;
		
		for (auto e : adj[u]) {
			ll v = e.fi, w = e.se;
			
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                h.push({D[v], v});
                trace[v] = u;
            }
		}
	}
}

void Find_path(int st, int en) {
	if (en != st && trace[en] == -1) {
		fp = 0;
	}
	
	while (en != -1) {
		path.pb(en);
		en = trace[en];
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    Pre(n);
    
    for (int i = 1; i <= m; ++i) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }
    
    Dijkstra(1, n);
    Find_path(1, n);
    
    if (fp == 0) cout << "-1" << endl;
    else {
    	for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << " ";
    }
    return 0;
}
