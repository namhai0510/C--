#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
const int base = 31;

ll n, q;
ll par[maxn + 2], alt[maxn + 2], querries[maxn + 2], d[maxn + 2];
vector<ll> ans;
pair<ll, ll> a[maxn + 2];

void make_set(int n) {
	for (int i = 1; i <= n; ++i) {
	    par[i] = i;
	    alt[i] = 1;
    }
}

int find_set(int u) {
    if (par[u] == u) return u;
    return par[u] = find_set(par[u]);
}

void union_sets(int a, int b) {
   	ll u = find_set(a), v = find_set(b);
   	
    if (u == v) return;
    	
    if (alt[u] > alt[v]) swap(u, v);
    
    par[u] = v;
    ans.pb(alt[u] * alt[v]);
    alt[v] += alt[u]; 
}

void Input() {
	cin >> n;
	
	make_set(n);
	
	for (int i = 1; i <= n - 1; ++i)
		cin >> a[i].fi >> a[i].se;
	
	cin >> q;
	
	for (int i = 1; i <= q; ++i) {
		cin >> querries[i];
		d[querries[i]] = 1;
	}
}

void Process() {
	for (int i = 1; i <= n - 1; ++i) {
        if (d[i] == 1) continue;
        union_sets(a[i].fi, a[i].se);
    }
    
	ans.clear();
    for (int i = q; i >= 1; --i) union_sets(a[querries[i]].fi, a[querries[i]].se);
    
    reverse(ans.begin(),ans.end());
    for (auto val : ans) cout << val << endl;
}

int main() {
    nothing
    if (fopen("WTREE.inp", "r")) {
        freopen("WTREE.inp", "r", stdin);
        freopen("WTREE.out", "w", stdout);
    }
    
    Input();
    Process();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
