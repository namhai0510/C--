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

ll n;
ll a[maxn + 2], b[maxn - 2];
ll dp[maxn + 2][5];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n - 1; ++i) cin >> b[i];
}

void Process() {
	dp[1][0] = a[1];
    dp[1][1] = b[1];
    
    for (int i = 2 ; i <= n; ++i) {
    	dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) * a[i]) % modd;
    	dp[i][1] = ((dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) * b[i]) % modd;
    	dp[i][2] = ((dp[i - 1][0] + dp[i - 1][2]) * b[i - 1] + dp[i - 1][1] * (b[i - 1] - 1)) % modd;
    }
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % modd << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    
    Input();
    Process();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
