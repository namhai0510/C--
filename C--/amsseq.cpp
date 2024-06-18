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

ll n, k, a[maxn + 2], dp[maxn + 2];
ll ret = -oo;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	dp[i] = -oo;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = i - 1; j >= max(i - k, 0LL); --j) {
    		dp[i] = max(dp[i], dp[j] + a[i]);
    	}
    }
    
    for (int i = 1; i <= n; ++i) ret = max(ret, dp[i]);
    
    cout << ret << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/amsseq
