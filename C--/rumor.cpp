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

ll n, m, c[maxn + 2];
ll ans = 0;
vector<ll> adj[maxn + 2];
bool visited[maxn + 2];

ll DFS(ll st) {
	ll cost = c[st], u;
	visited[st] = 1;
	
	for (int i = 0; i < adj[st].size(); ++i) {
		u = adj[st][i];
		
		if (visited[u] == 0) {
			cost = min(cost, DFS(u));
		}
	}
	
	return cost;
}
int main() {
    nothing
    if (fopen("rumor.inp", "r")) {
        freopen("rumor.inp", "r", stdin);
        freopen("rumor.out", "w", stdout);
    }
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> c[i];
    }
    
    for (int i = 1; i <= m; ++i) {
    	ll x, y; cin >> x >> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) ans += DFS(i);
	}
	
	cout << ans << endl;
    return 0;
}
