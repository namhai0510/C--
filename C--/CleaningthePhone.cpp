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

ll t, n, m, a[maxn + 2], cur[3];
vector<ll> type[3];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> m;
    	
    	type[1].clear();
    	type[2].clear();
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	
    	for (int i = 1; i <= n; ++i) {
    		ll x; cin >> x;
    		type[x].pb(a[i]);
    	}
    	
    	sort(type[1].rbegin(), type[1].rend());
    	sort(type[2].rbegin(), type[2].rend());
    	
    	cur[1] = cur[2] = 0;
    	
    	for (auto it : type[2]) cur[2] += it;
    	
    	int r = type[2].size();
    	
    	int ans = INT_MAX;
		for (int l = 0; l <= type[1].size(); ++l) {
			while (r > 0 && cur[1] + cur[2] - type[2][r - 1] >= m) {
				r--;
				cur[2] -= type[2][r];
			}
			
			if (cur[2] + cur[1] >= m) {
				ans = min(ans, 2 * r + l);
			}
			
			if (l != type[1].size()) {
				cur[1] += type[1][l];
			}
			
			// cout << ans <<  " " << cur[2] << " " << cur[1] << endl;
		}
		cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1475/D