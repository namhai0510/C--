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

ll a[4], b[4];
ll x, y;

ll CheckSquare(ll val) {
	ll ret = sqrt(val);
	
	if (ret * ret == val) return ret;
	ret++;
	if (ret * ret == val) return ret;
	
	return 0; 
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    for (int i = 1; i <= 3; ++i) {
    	cin >> a[i] >> b[i];
    	
    	if (a[i] > b[i]) swap(a[i], b[i]);
    }
    
    x = a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    y = CheckSquare(x);
    
    if (y == 0) {
    	cout << 0;
    	return 0;
    }
    
    if (b[1] == b[2] && b[2] == b[3] && b[3] == y) cout << y;
    else {
		if (b[2] == y) {
			swap(a[1], a[2]); 
			swap(b[1], b[2]);
		}
		
		if (b[3] == y) {
			swap(a[1], a[3]); 
			swap(b[1], b[3]);
		}
		
		if (b[1] == y) {
			a[1] = y - a[1];
			if ((a[2] == a[1] && a[3] == a[1]) || (b[2] == a[1] && a[3] == a[1]) || (a[2] == a[1] && b[3] == a[1]) || (b[2] == a[1] && b[3] == a[1]))  cout << y;
			else cout << 0;
		}		
		else cout << 0;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
