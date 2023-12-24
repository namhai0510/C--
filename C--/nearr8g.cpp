#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, a[maxn + 2], pos = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    
    ll x = m, y = 1;
    
    while (y <= n) {
    	ll i = x, j = y;
    	while (i <= m && j <= n) {
    		pos++;
    		a[(i - 1) * n + j] = pos;
    		i++; j++;
    	}
    	
    	if (x > 1) x--;
    	else y++;
    }
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) cout << a[(i - 1) * n + j] << " ";
    	cout << "\n";
    }
    return 0;
}
