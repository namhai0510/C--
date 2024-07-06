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

ll n, w, h, mx = -1, st = 0;
pair<pair<ll, ll>, ll> a[maxn + 2];
ll dp[maxn + 2], trace[maxn + 2];
vector<ll> card;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> w >> h;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].fi.fi >> a[i].fi.se;
    	a[i].se = i;
    	
    	dp[i] = 1;
    	trace[i] = 0;
    }
    
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	if (a[i].fi.fi <= w || a[i].fi.se <= h) continue;
    	
    	if (dp[i] > mx) {
    		mx = dp[i];
    		st = i;
    	}
    	
    	for (int j = 1; j < i; ++j) {
    		if (a[j].fi.fi <= w || a[j].fi.se <= h) continue;
    		
            if (a[i].fi.fi > a[j].fi.fi && a[i].fi.se > a[j].fi.se && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
                
                if (dp[i] > mx) {
                    mx = dp[i];
                    st = i;
                }
            }
    	}
    }
    
    while (st != 0) {
        card.pb(a[st].se);
        st = trace[st];
    }
    
    cout << card.size() << endl;
    for (int i = card.size() - 1; i >= 0; --i) cout << card[i] << " ";
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
// https://codeforces.com/problemset/problem/4/D
