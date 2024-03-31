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
const int maxa = 5e3 + 5;

ll n, m, cost[maxn + 2], ans = 0, res = +oo;
vector<ll> adj[maxn + 2];

ll ccom = 0, timedfs = 0, num[maxn + 2], low[maxn + 2];
stack<ll> vertex;

bool del[maxn + 2];
vector<ll> scc[maxn + 2];

void Dfs (int u) {
    low[u] = num[u] = ++timedfs;
    vertex.push(u);
    
    for (auto v : adj[u]) {
        if (del[v]) continue;
        
        if (!num[v]) {
            Dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], low[v]);
        }
    }
    
    
    if (low[u] == num[u]) {
        ++ccom;
        
        int v;
        do {
            v = vertex.top();
            scc[ccom].pb(v);
            vertex.pop();
            del[v] = 1;
        }
        while (v != u);
    }
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    memset(del, 0, sizeof(del));
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    
    cin >> m;
    
    for (int i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        
        adj[u].pb({v});
    }
    
    for (int u = 1; u <= n; ++u) {
        if (!num[u]) Dfs(u);
    }
    
    ll cnt = 1, tmp = 1;

    for (int i = 1; i <= ccom; ++i) {
        res = +oo; tmp = 1;
        for (auto it : scc[i]) {
            if (res > cost[it]) {
                res = min(res, cost[it]);
                tmp = 1;
            }
            else if (res == cost[it]) tmp++;
        }
        ans += res;
        cnt *= tmp;
        cnt %= modd;
    }
    
    cout << ans << " " << cnt << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/427/C