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
const ll modd = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, m;
vector<ll> adj[maxn + 2];
ll type[maxn + 2], cnt[3];

bool odd = 0;
ll P2[maxn + 2], res = 1;

void Dfs(ll u, ll c) {
	type[u] = c;
	cnt[c]++;
	
	for (auto v : adj[u]) {
		if (type[v] == -1) Dfs(v, 1 - c);
		
		if ((type[u] ^ type[v]) == 0) odd = 1;
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    P2[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
    	P2[i] = (P2[i - 1] * 2) % modd;
    }
    cin >> t;
    
    while (t--) {
    	cin >> n >> m;
    	
    	for (int i = 1; i <= n; ++i) {
    		adj[i].clear();
    		type[i] = -1;
    	}
    	
    	for (int i = 1; i <= m; ++i) {
    		ll u, v;
    		cin >> u >> v;
    		
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	
    	res = 1;
    	
    	for (int i = 1; i <= n; ++i) {
    		if (type[i] != -1) continue;
    		
    		odd = 0;
    		cnt[0] = cnt[1] = 0;
    		
    		Dfs(i, 0);
    		
    		if (odd == 1) {
    			cout << "0" << endl;
    			break;
    		}
    		
    		ll cur = (P2[cnt[0]] % modd + P2[cnt[1]] % modd + modd) % modd;
    		
    		res = (res * 1 * cur + modd) % modd;
    	}
    	
    	if (!odd) cout << res << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1093/D