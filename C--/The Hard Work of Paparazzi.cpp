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

struct Data {
	ll t, x, y;
};

ll r, n;
Data a[maxn + 2];
ll dp[maxn + 2], mxp[maxn + 2];

void Input() {
	cin >> r >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].t >> a[i].x >> a[i].y;
		
		dp[i] = -oo;
	}
}

void Process() {
	a[0].x = a[0].y = 1;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = max(0LL, i - 2 * r); j < i; ++j) {
			if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		
		if (i > 2 * r) 
			dp[i] = max(dp[i], 1 + mxp[i - 2 * r]);
			
		mxp[i] = max(dp[i], mxp[i - 1]);
	}
	
	cout << mxp[n] << endl;
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

// https://codeforces.com/problemset/problem/1427/C
