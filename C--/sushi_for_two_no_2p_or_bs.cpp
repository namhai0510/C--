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

ll n, t[maxn + 2], leng = 0, ans = 0;
vector<pair<ll, ll>> a;

int main() {
    nothing
    if (fopen("sushi_for_two.inp", "r")) {
        freopen("sushi_for_two.inp", "r", stdin);
        freopen("sushi_for_two.out", "w", stdout);
    }
    cin >> n;
    t[n + 1] = 3; t[0] = 0;
    for (int i = 1; i <= n + 1; ++i) {
    	cin >> t[i];
    	if (t[i] != t[i - 1]) {
    		a.pb({t[i - 1], leng});
    		leng = 1;
    	}
    	else leng++;
    }
    
    // for (auto it : a) cout << it.fi << " " << it.se << endl;
    
    for (int i = 2; i < a.size(); ++i) {
    	ans = max(ans, min(a[i].se, a[i - 1].se));
    }
    
    cout << ans * 2 << endl;
    return 0;
}