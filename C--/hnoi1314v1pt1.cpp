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

ll n, a[maxn + 2];
ll minval[maxn + 2], maxval[maxn + 2], res = -oo;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	minval[0] = +oo;
	for (int i = 1; i <= n; ++i) minval[i] = min(minval[i - 1], a[i]);
	maxval[n + 1] = -oo;
	for (int i = n; i >= 1; --i) maxval[i] = max(maxval[i + 1], a[i]);
	
	for (int i = 1; i <= n - 1; ++i) res = max(res, maxval[i + 1] - minval[i]);
	
	cout << res << endl;  
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
