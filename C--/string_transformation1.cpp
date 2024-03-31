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

ll t, n;
string A, B;

bool ok = 1;
ll res = 0;
vector<ll> adj[50];
bool vis[maxn + 2];

void Dfs(int u) {
	vis[u] = 1;
	
	for (auto v : adj[u]) {
		if (!vis[v]) Dfs(v);
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	res = 20; ok = 1;
    	for (int i = 0; i <= 40; ++i) {
    		vis[i] = 0;
    		adj[i].clear();
    	}
    	
    	cin >> n >> A >> B;
    	
    	A = '#' + A;
    	B = '#' + B;
    	
    	for (int i = 1; i <= n; ++i) {
    		if (A[i] > B[i]) {
    			ok = 0;
    			break;
    		}
    		else if (A[i] != B[i]) {
    			adj[A[i] - 'a' + 1].pb(B[i] - 'a' + 1);
    			adj[B[i] - 'a' + 1].pb(A[i] - 'a' + 1);
    		}
    	}
    	
    	if (ok == 0) {
    		cout << "-1" << endl;
    		continue;
    	}
    	
    	for (int i = 1; i <= 20; ++i) {
    		if (!vis[i]) {
    			Dfs(i);
    			res--; 
    		}
    	}
    	
    	cout << res << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1383/A