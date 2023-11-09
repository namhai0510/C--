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

int Bs2 (int x, int pre) {
	// be nhat lon hon bang
    int l, r, mid;
    l= pre + 1; r = m;
    while (l <= r) {
        mid = (l + r) / 2;
        if (b[mid] >= x) r = mid - 1;
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
    b[m + 1] = +oo;
    
    // co dinh con a[i], tim con b[j] dau tien ma a[i] co the mac duoc
    // a[i] - x <= b[j] => b[j] be nhat lon hon bang a[i] - x
    // a[i] + y >= b[j] => b[j] lon nhat be hon bang a[i] + y
    
    int p = 0;
    for (int i = 1; i <= n; ++i) {
    	ll it1 = Bs2(a[i] - x, p);
    	// cout << it1 << endl;
    	
    	if (it1 > m || it1 < 1 || (b[it1] < a[i] - x) || (b[it1] > a[i] + y)) continue;
    	
    	p = it1;
    	ans.pb({i, it1});
    }
    
    cout << ans.size() << endl;
    for (auto it : ans) cout << it.fi << " " << it.se << endl;
    
    return 0;
}