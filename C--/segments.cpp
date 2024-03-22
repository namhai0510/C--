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

ll n, a[maxn + 2], ps[maxn + 2], ans = 0, p;
map<ll, ll> mark;

int main() {
    nothing
    if (fopen("segments.inp", "r")) {
        freopen("segments.inp", "r", stdin);
        freopen("segments.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	ps[i] = ps[i - 1] + a[i];
    	mark[ps[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) {
    	if (ps[n] % ps[i] == 0) {
    		for (p = ps[i]; p <= ps[n]; p += ps[i]) {
    			if (mark[p] == 0) break;
    		}
    		
    		if (p - ps[i] == ps[n]) {
    			cout << ps[n] / ps[i] << endl;
    			return 0;
    		}
    	}
    }
    return 0;
}
