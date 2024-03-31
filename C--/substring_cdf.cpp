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

ll m, n;
string s;
vector<ll> adj[maxn + 2];

ll deg[maxn + 2];
vector<ll> topo;
queue<ll> source;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    cin >> s;
    
    s = '#' + s;
    
    for (int i = 1; i <= m; ++i) {
    	ll x, y;
    	cin >> x >> y;
    	
    	adj[x].pb(y);
    	deg[y]++;
    }
    
    for (int u = 1; u <= n; ++u) 
    	if (!deg[u]) {
    		source.push(u);
    	}
    
    while (!source.empty()) {
    	int u = source.front();
    	
    	source.pop();
    	topo.pb(u);
    	
    	for (auto v : adj[u]) {
    		deg[v]--;
    		
    		if (!deg[v]) source.push(v);
    	}
    }
    
    if (topo.size() < n) {
    	cout << "-1";
    	return 0;
    }
    
    ll ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        vector<ll> dp(n + 1, 0);
        
        for (ll i : topo) {
            dp[i] += (s[i] == c);
            
            for (ll to : adj[i]) {
                dp[to] = max(dp[to], dp[i]);
            }
            
            ans = max(ans, dp[i]);
        }
    }
    
    cout << ans << endl;
        
    return 0;
}

// https://codeforces.com/problemset/problem/919/D