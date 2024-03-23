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
vector<pair<ll, pair<ll,ll>>> adj[maxn + 2];
ll D[maxn + 2];
int train[maxn + 2];

ll nd = 0;
bool fp = 1;

void Dijkstra() {
	for (int i = 1; i <= n; ++i) {
		D[i] = +oo;
	}
	D[1] = 0;
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> h;
	h.push({D[1], 1});
	
	while (!h.empty()) {
		pair<ll, ll> x = h.top();
		h.pop();
		
		int u = x.se, c = x.fi;
		
		if (c > D[u]) continue;
		
		for (auto e : adj[u]) {
			ll v = e.fi, w = e.se.fi;
			
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                h.push({D[v], v});
            }
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> k;
    
    for (int i = 1; i <= m; ++i) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	
    	adj[u].pb({v, {w, 0}});
    	adj[v].pb({u, {w, 0}});
    }
        
    for (int i = 1; i <= k; ++i) {
    	ll v, w;
    	cin >> v >> w;
    	adj[1].pb({v, {w, 1}});
    	adj[v].pb({1, {w, 1}});
    	train[v] = 1;
    }
    
    Dijkstra();
    
    nd = 0;
    for (int u = 2; u <= n; ++u) {
		bool c = 1;
		if (!train[u]) continue;
		
		for (auto e : adj[u]) {
			if(e.se.se) continue;
			
			ll v = e.fi, w = e.se.fi;
			
			if (D[u] == D[v] + w) c = 0;
		}
		
		nd += c;
	}
    cout << k - nd << endl;
    return 0;
}
