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

ll n;
ll a[55][55], d[maxn + 2];

int main() {
    nothing
    if (fopen("tournament.inp", "r")) {
        freopen("tournament.inp", "r", stdin);
        freopen("tournament.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n * (n - 1) / 2 - 1; ++i) {
    	ll u, v; cin >> u >> v;
    	a[max(u, v)][min(u, v)] = 1;
    	d[u]++;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= i - 1; ++j) {
    		if (a[i][j] == 0) {
    			if (d[i] > d[j]) cout << i << " " << j << endl;
    			else cout << j << " " << i << endl;
    			a[i][j] = 1;
    		}
    	}
    }
    
    return 0;
}
