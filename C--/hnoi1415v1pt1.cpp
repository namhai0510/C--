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

ll n, cnt = 0;
ll f[maxn + 2], dp[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> n;
	
	f[5] = 2;
	for (int i = 6; i <= n; ++i) {
		cnt += (i % 2 == 0);
		
		f[i] = f[i - 1] + cnt;
	}   
	
	dp[4] = 1;
	for (int i = 5; i <= n; ++i) dp[i] = (dp[i - 1] + f[i]) % mod;
	
	cout << dp[n] << endl;
	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
