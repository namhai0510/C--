#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, a, b, t[3][maxn + 2], ans = +oo;

vector<pair<ll, ll>> tree;
map<ll, ll> used;

ll Bs2(ll x, int type, int pre) {
	int l = pre, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (t[type][mid] - t[type][pre - 1] >= x) r = mid - 1;
		else l = mid + 1;
	}
	
	return l;
}
int main() {
    nothing
    if (fopen("voi14_ex1.inp", "r")) {
        freopen("voi14_ex1.inp", "r", stdin);
        freopen("voi14_ex1.out", "w", stdout);
    }
    cin >> n >> a >> b;
    
    tree.pb({0, 0}); t[1][0] = 0; t[2][0] = 0;
    for (int i = 1; i <= n; ++i) {
    	ll d, type;
    	cin >> d >> type;
    	tree.pb({d, type});
    }
    sort(tree.begin(), tree.end());
    
    for (int i = 1; i <= n; ++i) {
    	t[1][i] = t[1][i - 1];
    	t[2][i] = t[2][i - 1];
    	t[tree[i].se][i]++;
    }
    
    for (int i = 1; i <= n; ++i) {
    	ll it1 = Bs2(a, 1, i), it2 = Bs2(b, 2, i);
    	
    	if (t[1][it1] - t[1][i - 1] >= a && t[2][it2] - t[2][i - 1] >= b)
    		ans = min(ans, tree[max(it1, it2)].fi - tree[i].fi);
    }
    
    if (ans == +oo) cout << -1;
    else cout << ans << endl;
    
    return 0;
}