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
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, q, a[maxn + 2], b[maxn + 2], dif[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	cin >> b[i];
    }
     
    for (int i = 1; i <= n; ++i) {
    	dif[i] = a[i] - b[i];
    }
    sort(dif + 1, dif + 1 + n);
    
    dif[n + 1] = +oo;
    
    while (q--) {
    	ll x, y, tmp;
    	cin >> x >> y;
    	
    	ll it = upper_bound(dif + 1, dif + 1 + n, y) - dif;
    	
    	tmp = it - 1;
    	
    	if (n - tmp >= x) cout << 1;
    	else cout << 0;
    	
    	// cout << " " << n - tmp << " " << x << " " << it << endl;
    }
    return 0;
}

// co q truy van, moi truy van dua ra s >= x hay khong
// voi s la so luong so ma b[i] + y < a[i]
// (x, y) de bai cho
