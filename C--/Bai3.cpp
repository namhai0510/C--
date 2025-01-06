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

ll n, m, p, res = 0;
ll a[maxn + 2], b[maxn + 2], c[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> p;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= m; ++j) cin >> b[j];
    for (int k = 1; k <= p; ++k) cin >> c[k];
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    sort(c + 1, c + 1 + p);
    
    for (int j = 1; j <= m; ++j) {
        ll countA = lower_bound(a + 1, a + 1 + n, b[j]) - a;
        ll countC = c - upper_bound(c + 1, c + 1 + p, b[j]);
        
        res += countA * countC;
    }
	
	cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
