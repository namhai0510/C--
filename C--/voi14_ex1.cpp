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

ll n, a, b, t[3], ans = +oo;

vector<pair<ll, ll>> tree;
map<ll, ll> used;

int main() {
    nothing
    if (fopen("voi14_ex1.inp", "r")) {
        freopen("voi14_ex1.inp", "r", stdin);
        freopen("voi14_ex1.out", "w", stdout);
    }
    cin >> n >> a >> b;
    
    tree.pb({0, 0}); t[1] = 0; t[2] = 0;
    for (int i = 1; i <= n; ++i) {
    	ll d, type;
    	cin >> d >> type;
    	tree.pb({d, type});
    }
    sort(tree.begin(), tree.end());
    
    // for (int i = 1; i <= n; ++i) cout << tree[i].fi << " " << tree[i].se << endl;
    // cout << "-------------" << endl;
    
    ll st = 1, en = 0;
    for (st = 1; st <= n; ++st) {
    	while ((t[1] < a || t[2] < b) && en < n) {
    		en++;
    		t[tree[en].se]++;
    	}
    	
    	if (t[1] >= a && t[2] >= b) {
    		// cout << st << " " << en << " " << t[1] << " " << t[2] << " " << ans << endl;
    		ans = min(ans, tree[en].fi - tree[st].fi);
    	}
    	
    	t[tree[st].se]--;
    }
    if (ans == +oo) cout << -1;
    else cout << ans << endl;
    
    return 0;
}