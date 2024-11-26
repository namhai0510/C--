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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, m, a[maxn + 2];
unordered_set<ll> res;

int main() {
    nothing
    if (fopen("SODEP.inp", "r")) {
        freopen("SODEP.inp", "r", stdin);
        freopen("SODEP.out", "w", stdout);
    }
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	for (int i = 1; i <= n; ++i) {
		for (int x = 1; ;++x) {
			if (a[i] * x > m) break;
			
			res.insert(a[i] * x);
		}
	}
	
	cout << res.size() << endl;
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}