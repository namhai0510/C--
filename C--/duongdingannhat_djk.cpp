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

struct Edge{
    ll v, w;
};

struct Node{
    ll u, Dist_u;
};

struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

vector<vector<Edge>> E;
vector<ll> D, trace;
priority_queue<Node, vector<Node>, cmp> h;
vector<bool> P;

void Dijkstra(int n, int s) {
    D[s] = 0;
    
    h.push({s, D[s]});

    while(!h.empty()) {
        Node x = h.top();
        h.pop();

        ll u = x.u;
        if (P[u] == 1) continue;

        P[u] = true;
        for (auto e : E[u]) {
            ll v = e.v;
            ll w = e.w;

            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                h.push({v, D[v]});
                trace[v] = u;
            }
        }
    }
}

ll n, m, x, y;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> x >> y;
    
    E.resize(n + 2);
    D.resize(n + 2, +oo);
    trace.resize(n + 2, -1);
    P.resize(n + 2, 0);
    
    for (int i = 1; i <= m; ++i) {
    	ll u, v, w;
    	cin >> u >> v >> w;	
    	E[u].pb({v, w});
    	E[v].pb({u, w});
    }
    
    Dijkstra(y, x);
    
    cout << D[y] << endl;  
    
    return 0;
}
