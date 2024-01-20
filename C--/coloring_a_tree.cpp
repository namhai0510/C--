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

ll n, c[maxn + 2], p[maxn + 2], res = 0;
vector<ll> adj[maxn + 2];

ll Dfs(ll u, ll f, ll color) {
	if (c[u] != color) res++;
	
	for (int i = 0; i < adj[u].size(); ++i) {
		ll v = adj[u][i];
		
		if (v == f) continue;
		
		Dfs(v, u, c[u]);
	}
	
	return 0;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    memset(c, 0, sizeof(c));
    
    cin >> n;
    for (int i = 2; i <= n; ++i) {
    	cin >> p[i];
    	adj[p[i]].pb(i);
    	adj[i].pb(p[i]);
    }
    
    for (int i = 1; i <= n; ++i) cin >> c[i];
    
    Dfs(1, -1, -1);
    
    cout << res << endl;
    return 0;
}
