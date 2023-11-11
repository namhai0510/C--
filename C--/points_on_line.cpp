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

ll n, d, a[maxn + 2];

int Bs3 (int x, int pre) {
	// lon nhat be hon bang
    int l, r, mid;

    l = pre; r = n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    
    return r;
}

ll cnt = 0;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    for (int i = 1; i <= n - 2; ++i) {
    	ll it = Bs3(a[i] + d, i) - i + 1;
    	// cout << it << endl;
    	
    	cnt += (it - 1) * (it - 2) / 2;
    }
    cout << cnt << "\n";
    return 0;
}