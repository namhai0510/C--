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
const ll modd = 998244353;
const int maxn = 2e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, dp[maxn + 2], S = 1;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) 
    	for (int j = i * 2; j <= n; j += i) dp[j]++;
    	
    dp[0] = S = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + S) % modd;
        S = (S + dp[i]) % modd;
    }
    cout << dp[n] << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1528/B
