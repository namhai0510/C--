#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, k, a[maxn + 2], psum[maxn + 2], ans = -2;

int main() {
    nothing
    if (fopen("girls.inp", "r")) {
        freopen("girls.inp", "r", stdin);
        freopen("girls.out", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
    	cin >> a[i];
    }
    
    sort(a + 1, a + 1 + m);
    
    for (int i = 1; i <= m; ++i) {
    	psum[i] = psum[i - 1] + a[i];
    }
    
    for (int i = 1; i <= m - n + 1; ++i) {
    	if (a[i + n - 1] - a[i] > k) continue;
    	else ans = max(ans, psum[i + n - 1] - psum[i - 1]);
    	// cout << psum[i + n - 1] << " " << psum[i - 1] << endl;
    }
    
    cout << ans;
    return 0;
}