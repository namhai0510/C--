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
const int base = 31;

string t, p;
ll n, m, a[maxn + 2], tmp = 1, ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t >> p;
    
    n = t.size();
    m = p.size();
    
	t = '#' + t;
	p = '#' + p;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	ll l = 0, r = n, mid;
	
	while (l <= r) {
		tmp = 1;
		mid = (l + r) / 2;
		string now = t;
		
		for (int i = 1; i <= mid; ++i) now[a[i]] = '#';
		
		for (int j = 1; j <= m; ++j) {
			while (tmp <= n && p[j] != now[tmp]) ++tmp;
			
			++tmp;
		}
			
		if (tmp <= n + 1) ans = mid, l = mid + 1;
		else r = mid - 1;
		
		// cout << tmp << " " << ans << endl;
	}
	
	cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/778/A
