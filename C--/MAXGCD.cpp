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

ll n, ans = 0, a[maxn + 2], dp[3][maxn + 2];

int main() {
    nothing
    if (fopen("MAXGCD.inp", "r")) {
        freopen("MAXGCD.inp", "r", stdin);
        freopen("MAXGCD.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    if (n == 1) {
    	cout << a[1] << endl;
    	return 0;
    }
    
    dp[1][1] = a[1];
    dp[2][n] = a[n];
    
    for (int i = 2; i <= n; ++i) dp[1][i]= __gcd(dp[1][i - 1], a[i]);
	for (int i= n - 1; i >= 1; --i) dp[2][i]=__gcd(dp[2][i + 1], a[i]);

	for (int i = 2; i <= n - 1; ++i) ans = max(ans, __gcd(dp[1][i - 1], dp[2][i + 1]));
	
	ans = max(ans, dp[1][n - 1]);
	ans = max(ans, dp[2][2]);
	
	cout << ans << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
