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

ll n, m, x, y, a[maxn + 2], b[maxn + 2];

int Bs2(ll x, int pre) {
	// tim vi tri be nhat >= x trong mang
    int l, r, mid;
    l = pre + 1; r = n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    
    return l;
}

vector<pair<ll, ll>> ans;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> x >> y;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    a[n + 1] = +oo;
    
    int p = 0;
    for (int j = 1; j <= m; ++j) {
    	// tim nhung con ma co the mac duoc b[j]
    	// a[i] - x <= b[j] <= a[i] + y;
    	// b[j] + x >= a[i] && b[j] - y <= a[i];
    	
    	ll it1 = Bs2(b[j] - y, p);
    	// cout << it1 << endl;
    	
    	if (it1 > n || it1 < 1 || (a[it1] - x > b[j]) || (a[it1] + y < b[j])) continue;
    	
    	p = it1;
    	ans.pb({it1, j});
    }
    
    cout << ans.size() << endl;
    for (auto it : ans) cout << it.fi << " " << it.se << endl;
     
    return 0;
}