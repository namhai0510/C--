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

ll n, timedfs = 0;
vector<ll> adj[maxn + 2], st;

void Dfs(ll u, ll height) {
	for (int i = 0; i < adj[u].size(); ++i) {
		Dfs(adj[u][i], height + 1);
	}
	
	timedfs = max(timedfs, height);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	int x; cin >> x;
    	if (x == -1) st.pb(i);
    	else adj[x].pb(i);
    }
    
    for (auto it : st) {
    	Dfs(it, 1);
    }
    
    cout << timedfs << endl;
    
    return 0;
}
