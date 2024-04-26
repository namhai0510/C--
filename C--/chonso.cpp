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

ll n, m, it = 0, ans = +oo;
pair<ll, ll> a[maxn + 2];
map<ll, ll> cnt;

ll enough = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		it++;
    		cin >> a[it].fi;
    		a[it].se = i;
    	}
    }
    sort(a + 1, a + 1 + it);
    
    // for (int i = 1; i <= it; ++i) cout << a[i].fi << " " << a[i].se << endl;
    // cout << "----" << endl;
    
    int l = 1, r = 1;
    
    for (l = 1; l <= it; ++l) {
    	while (r <= it && enough < n) {
    		cnt[a[r].se]++;
    		enough += (cnt[a[r].se] == 1);
    		
    		// cout << l << " " << r << " " << enough << " " << a[r].se << " " << cnt[a[r].se] << endl;
    		
    		r++;
    	}
    	
    	if (r > it) break;
    	
    	if (enough == n && r > l) 
    			ans = min(ans, a[r - 1].fi - a[l].fi);
    			
    	cnt[a[l].se]--;
    	enough -= (cnt[a[l].se] == 0);
    }
    
    cout << ans << endl;
    return 0;
}
