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
const int maxa = 1e3;
const int base = 31;

ll n, k, p, a[maxn + 2], b[maxn * 2 + 2];
ll dp[maxa + 2][maxa * 2 + 2];

void Input() {
	cin >> n >> k >> p;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 1; j <= k; ++j) cin >> b[j];
	
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + k);
}

void Process() {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j) dp[i][j] = +oo;
	
	for (int j = 0; j <= k; ++j) dp[0][j] = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p)),
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[n][k] << endl;
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

// https://codeforces.com/problemset/problem/830/A
