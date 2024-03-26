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

ll n, p[maxn + 2];
map<ll, ll> mark;

ll dp[maxn + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> p[i];
    	mark[p[i]]++;
    }
    sort(p + 1, p + 1 + n);
    
    dp[maxn + 1] = 0;
    
    for (int i = maxn; i >= 1; --i) {
    	dp[i] = dp[i + 1];
    	
    	if (mark[i] > 0) dp[i] += mark[i];
    	
    	ans = max(ans, i * dp[i] - i * max(mark[i] - 1, 0 * 1LL));
    }
    
    cout << ans << endl;
    return 0;
}
