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

ll n, a[maxn + 2], b[maxn + 2], f[maxn + 2], path[maxn + 2];
vector<ll> trace; 
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    
    f[0] = 0;
	f[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		f[i] = min(f[i - 1] + a[i], f[i - 2] + b[i - 1]);
		
		if (f[i] != f[i - 1] + a[i]) path[i] = 2;
		else path[i] = 1;
	}
	
	for(int i = n; i >= 1; --i) {
		if (path[i] == 2) {
			trace.pb(i);
			--i;
		}
	}
	
	sort(trace.begin(),trace.end());
	cout << f[n] << endl;
	for (int i = 0; i < trace.size(); ++i) cout << trace[i] << " ";
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
