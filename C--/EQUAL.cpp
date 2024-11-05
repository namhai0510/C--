#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, a[maxn + 2];
ll SumSquare = 0, Sum = 0, Mn = +oo, Mx = -oo, res = +oo;

int main() {
    nothing
    if (fopen("EQUAL.inp", "r")) {
        freopen("EQUAL.inp", "r", stdin);
        freopen("EQUAL.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	SumSquare += a[i] * a[i];
    	Sum += a[i];
    	Mn = min(Mn, a[i]);
    	Mx = max(Mx, a[i]);
    }
    
    for (ll x = Mn; x <= Mx; ++x) {
    	// cout << SumSquare << " " << 2 * Sum * n << " " << x * x * n << endl;
    	// cout << SumSquare - 2 * Sum * x + x * x * n << endl;
    	
    	res = min(res, SumSquare - 2 * Sum * x + x * x * n);
    }
    
    cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
