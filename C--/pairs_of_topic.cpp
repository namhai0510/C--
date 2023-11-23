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

ll n, ans = 0;
struct Data {
	ll a, b, c;
} x[maxn + 2];

bool cmp (Data A, Data B) {
	return (A.c < B.c);
}

ll Bs2(ll val) {
    int l = 1, r = n, mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (x[mid].c < val) l= mid + 1;
        else r = mid - 1;
    }
    
    return l;
}

int main() {
    nothing
    if (fopen("pairs_of_topic..inp", "r")) {
        freopen("pairs_of_topic..inp", "r", stdin);
        freopen("pairs_of_topic..out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i].a;
    for (int i = 1; i <= n; ++i) cin >> x[i].b;
    for (int i = 1; i <= n; ++i) x[i].c = x[i].a - x[i].b;

    sort(x + 1, x + 1 + n, cmp);
    
    // for (int i = 1; i <= n; ++i) 
    	// cout << x[i].a << " " << x[i].b << " " << x[i].c << endl;
    // cout << " ---- " << endl;
    
    for (int i = 1; i <= n; ++i) {
    	if (x[i].c <= 0) continue;
    	
    	ll it = Bs2(-x[i].c + 1);
    	// cout << it << endl;
    	
    	ans += i - it;
    }
    cout << ans;
    
    return 0;
}