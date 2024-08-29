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
const int maxa = 5e3;
const int base = 31;

ll test;
ll n, m, a[maxa + 2];
ll res, dp[maxa + 2][maxa + 2];
pair<ll, ll> cnt[maxa + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	m = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[m].fi != a[i]) {
            cnt[++m].fi = a[i];
            cnt[m].se = 1;
        }
        else cnt[m].se++;
	}
}

void Process() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + cnt[i].se <= i - dp[i - 1][j] - 1) {
                dp[i][j + cnt[i].se] = max(dp[i][j + cnt[i].se], dp[i - 1][j] + 1);
            }
		}
	}
	
	res = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j <= i; ++j) {
			res = max(res, dp[i][j]);
			dp[i][j] = 0;
		}
		
	cout << m - res << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1987/D
