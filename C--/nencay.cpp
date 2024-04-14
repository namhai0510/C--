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

ll t, n, connect[maxn + 2], cnt = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	cnt = 0;
    	for (int i = 1; i <= n; ++i) connect[i] = 0;
    	
    	for (int i = 1; i <= n - 1; ++i) {
    		ll u, v;
    		cin >> u >> v;
    		connect[u]++;
    		connect[v]++;
    	}
    	
    	for (int i = 1; i <= n; ++i) {
    		if (connect[i] == 1) cnt++;
    	}
    	
    	cout << (cnt + 1) / 2 << endl;
    	
    }
    return 0;
}
