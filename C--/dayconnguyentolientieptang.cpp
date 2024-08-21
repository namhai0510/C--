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

ll n, a[maxn + 2], c[maxn + 2], ans = 0;
vector<ll> adj[maxn + 2];

ll fct[maxn + 2];
vector<ll> P, tmp;
void Sieve() {
	for (int i = 1; i <= maxn; ++i) fct[i] = i;
	
	for (int i = 2; i * i <= maxn; ++i) 
		if (fct[i] == i)
			for (int j = i * i; j <= maxn; j += i) fct[j] = i;
		
	for (int i = 2; i <= maxn; ++i) 
		if (fct[i] == i) P.pb(i);
}

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        
		vector<ll> now;
        ll x = a[i];
        while (x > 1) {
            if (c[fct[x]] == 0)
                now.pb(fct[x]), c[fct[x]]++; 
            
            x /= fct[x];
        }
        
        for (auto val : now) {
            c[val] = 0; 
            adj[val].pb(i); 
        }
    }
}

void Process() {
    for (auto x : P) {
        vector<pair<ll, ll>> t;
        for (auto e : adj[x]) t.pb({e, c[e - 1] + 1});
        
        for (auto e : tmp) c[e] = 0; 
        
        tmp.clear();
        
        for (auto e : t) {
            c[e.fi] = e.se;
            ans = max(ans, e.se);
            tmp.pb(e.fi); 
        }
    }
	
	cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Sieve();
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}