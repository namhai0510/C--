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

ll n, ans = 0;
pair<ll, ll> cost[maxn + 2], temp;

void Input() {
	cin >> n;
	
	cost[0].fi = cost[0].se = 0;
	for (int i = 1; i <= n; ++i) cin >> cost[i].fi >> cost[i].se;
	sort(cost + 1, cost + 1 + n);
}

void Process() {
	// for (int i = 1; i <= n; ++i) cout << cost[i].fi << " " << cost[i].se << endl;
	// cout << "----" << endl;
	
	temp.fi = cost[1].fi;
	temp.se = cost[1].se;
	ans += temp.fi;
	
	cout << ans << endl;
	
	for (int i = 2; i <= n; ++i) {
		if (ans + cost[i].fi - temp.fi + temp.se < ans + cost[i].se) {
			ans = ans + cost[i].fi - temp.fi + temp.se;
			temp.fi = cost[i].fi;
			temp.se = cost[i].se;
		}
		else ans += cost[i].se;
		
		cout << ans << endl;
	}
}
int main() {
    nothing
    if (fopen("POPUST.inp", "r")) {
        freopen("POPUST.inp", "r", stdin);
        freopen("POPUST.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
