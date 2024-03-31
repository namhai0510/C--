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

ll n, x[maxn + 2];
ll adj[maxa + 2][maxa + 2];

vector<ll> v, ans;
ll S;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ll w; cin >> w;
            adj[i][j] = w;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        v.pb(x);
    }
    v.pb(0);
    reverse(v.begin(), v.end());
    
    for (int k = 1; k <= n; ++k) {
        ll x = v[k];
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][x] + adj[x][j]);  
            }
        }
        
        S = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                S += adj[v[i]][v[j]];
            }
        }
        
        ans.pb(S);
    }
    
    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << " ";
    return 0;
}

// https://codeforces.com/problemset/problem/295/B