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

ll m, n;
ll k[maxn + 2], t[maxn + 2], ans = 0;
vector<pair<ll, ll>> serve;
void Input() {
	cin >> m >> n;
	
	for (int i = 1; i <= m; ++i) {
		cin >> k[i] >> t[i];
		ans += k[i];
		
		if (k[i] < t[i])
			serve.pb({k[i], 1});
		else 
			serve.pb({t[i], k[i] / t[i]}), serve.pb({k[i] % t[i], 1});
	}
	sort(serve.begin(), serve.end(), greater<pair<ll, ll>>());
}

void Process() {
	for (int i = 0; i < serve.size(); ++i) {
		if (n <= 0) break;
		
		ans -= min(n, serve[i].se) * serve[i].fi;
		n -= min(n, serve[i].se);
	}
	
	cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
