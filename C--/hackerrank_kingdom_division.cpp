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

ll n, dp[maxn][3];
vector<ll> adj[maxn + 2];

void Dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        Dfs(v, u);
    }
    // Duyet tat ca cac nhanh tu nut hien tai
    
    dp[u][0] = dp[u][1] = 1;
    // Ke ca cha cua u co trung mau voi u hay khong thi van chi tinh la 1 cach
    // Boi vi nut con luon phai trung mau voi nut cha
    
    for (auto v : adj[u]) {
        if (v == p) continue;
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % modd;
        dp[u][1] = dp[u][1] * dp[v][1] % modd;
    }
    dp[u][1] = (modd + dp[u][0] - dp[u][1]) % modd;
}
int main() {
    nothing
    if (fopen("kingdom_division.inp", "r")) {
        freopen("kingdom_division.inp", "r", stdin);
        freopen("kingdom_division.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    Dfs(1, 0);
    
    cout << 2 * dp[1][1] % modd;
    return 0;
}

// https://www.hackerrank.com/challenges/kingdom-division/problem?isFullScreen=true

// Solution:
// Goi dp[u][0] la so cach to mau cay con co goc la u thoa man par[u] == par[par[u]]
// Goi dp[u][1] la so cach to mau cay con co goc la u thoa man par[u] != par[par[u]]
// 
// Neu u khong co con, thi mau cua u chac chan se phai trung voi mau cua par[u]
// => dp[u][0] = dp[u][1] = 1 (u khong co con)
// 
// Su dung DFS de tinh ket qua tai moi nut
