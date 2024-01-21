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

ll n, l = 0, r = 0;
vector<ll> adj[maxn + 2];
bool vis[maxn + 2], type[maxn + 2];

void Dfs(ll u, ll ty) {
	vis[u] = 1;
	type[u] = ty;
	
	for (auto v : adj[u]) {
		if (!vis[v]) {
			Dfs(v, ty ^ 1);
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	ll u, v;
    	cin >> u >> v;
    	
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    Dfs(1, 0);
    
    for (int i = 1; i <= n; ++i) {
    	if (type[i] == 0) l++;
    	else r++;
    }
    
    cout << l * r - (n - 1) << endl;
    return 0;
}

// https://codeforces.com/contest/862/problem/B
