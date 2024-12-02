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

struct DATA {
	ll c, a;
};

ll n, q;
ll f[maxn + 2], S = 0;
DATA x[maxn + 2];
vector<ll> col[maxn + 2], ps[maxn + 2];

void Init() {
	for (int i = 0; i <= maxn; ++i) {
		f[i] = 0;
		col[i].pb(0);
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    Init();
    
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i].a >> x[i].c;
    	
    	col[x[i].c].pb(x[i].a);
    }
    
    for (int val = 1; val <= maxn; ++val) {
    	ps[val].resize(col[val].size() + 2, 0LL);
    	
    	for (int i = 1; i < col[val].size(); ++i) 
    		ps[val][i] = ps[val][i - 1] + col[val][i];
    }
    
    cin >> q;
    
    while (q--) {
    	ll type, color, y;
    	cin >> type >> color >> y;
    	
    	if (type == 1) {
    		S += y;
    		f[color] += y;
    	}
    	else {
    		ll l = 1, r = col[color].size() - 1, mid, res = 0;
    		
    		while (l <= r) {
    			mid = (l + r) / 2;
    			
    			if (ps[color][mid] + mid * (S - f[color]) <= y) {
    				res = mid;
    				l = mid + 1;
    			}
    			else r = mid - 1;
    		}
    		
    		cout << res << endl;
    	}
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
