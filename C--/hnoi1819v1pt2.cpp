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

ll n, res = 0;
ll a[maxn + 2], p[maxn + 2], cost[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 1; j <= n; ++j) cin >> p[j];
	
	cost[1] = p[1];
	for (int j = 2; j <= n; ++j)
		cost[j] = min(cost[j - 1], p[j]);
		
	for (int i = 1; i <= n; ++i) res += a[i] * cost[i];
	
	cout << res << endl;
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
