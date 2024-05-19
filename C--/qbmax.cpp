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
const int base = 31;

ll m, n, a[105][105], f[105][105];
ll b[105];
ll ans = -10005;

void back(int pos, long long x) {
	if (pos > n) {
		ans = max(ans, x);
		return;
	}
	
	for (int i = max(1LL, b[pos - 1] - 1); i <= min(b[pos - 1] + 1, m); ++i) {
		ll tp = x + a[i][pos];
		b[pos] = i;
		if (tp > f[i][pos]) {
			f[i][pos] = tp;
			back(pos + 1, tp);
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    for (int i = 1; i <= m; ++i) {
    	f[i][1] = a[i][1];
    	for (int j = 2; j <= n; ++j) f[i][j] = -10005;
    }

    for (int i = 1; i <= m; ++i) {
    	b[1] = i;
    	back(2, a[i][1]);
    }
    
    cout << ans << endl;
    return 0;
}
