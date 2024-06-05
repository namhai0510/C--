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
const int maxn = 2e5 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, w, ans = 0;
ll a[maxn + 2], b[maxn + 2], p[maxn + 2];
vector<ll> difa, difb;

void Init_Prefix() {
	int length = difb.size();
	
	for (int r = 1, l = 0; r < length; ++r) {
		if (difb[l] == difb[r]) {
			p[r] = ++l;
		}
		else if (l != 0) {
			l = p[l - 1];
			r--;
		}
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> w;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    for (int j = 1; j <= w; ++j) {
    	cin >> b[j];
    }
    
    if (w > n) cout << 0, exit(0);
    if (w == 1) cout << n, exit(0);
    
    for (int i = 2; i <= n; ++i) difa.pb(a[i] - a[i - 1]);
    for (int j = 2; j <= w; ++j) difb.pb(b[j] - b[j - 1]);
    
    Init_Prefix();
    
	for (int i = 0, j = 0; i < difa.size(); ++i) {
		if (difa[i] == difb[j]) {
			j++;
		} 
		else if (j != 0) {
			j = p[j - 1];
			--i;
		}
		
		if (j == difb.size()) {
			j = p[j - 1];
			ans++;
		}
	}
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/471/D
