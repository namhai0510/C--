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

ll test, n, a[maxn + 2];
ll tmp, ans;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
	while (test--) {
		cin >> n;
		
		for (int i = 1; i <= n; ++i) cin >> a[i];
		
		tmp = a[1];
		ans = 0;
		
		for (int i = 1; i <= n - 1; ++i) {
			ll x = a[i + 1] - a[i];
			
			ans += abs(x);
			if (x < 0) tmp += x;
		}
		
		ans += abs(tmp);
		cout << ans << endl;
	}
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1700/C
