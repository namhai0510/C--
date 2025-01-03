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
char a[maxa + 2][maxa + 2];
ll cnt = 0, res = 0;
pair<ll, char> tmp;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> m >> n;
    
    for (int i = 1; i <= m; ++i) 
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    		a[i][j + n] = a[i][j];
    	}
    
	cnt = res = 0;
    tmp.fi = 0;
    tmp.se = '.';
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		for (int k = j; k <= j + n; ++k) {
    			if (a[i][k] == 'D' || a[i][k] == 'T') cnt++;
    			else break;
    		}
    		
    		if (res < cnt) {
    			res = cnt;
    			tmp.fi = i;
    			tmp.se = 'D';
    		}
    		
    		cnt = 0;
    	}
    	
    	for (int j = 1; j <= n; ++j) {
    		for (int k = j; k <= j + n; ++k) {
    			if (a[i][k] == 'V' || a[i][k] == 'T') cnt++;
    			else break;
    		}
    		
    		if (res < cnt) {
    			res = cnt;
    			tmp.fi = i;
    			tmp.se = 'V';
    		}
    		
    		cnt = 0;
    	}
    	
    	for (int j = 1; j <= n; ++j) {
    		for (int k = j; k <= j + n; ++k) {
    			if (a[i][k] == 'X' || a[i][k] == 'T') cnt++;
    			else break;
    		}
    		
    		if (res < cnt) {
    			res = cnt;
    			tmp.fi = i;
    			tmp.se = 'X';
    		}
    		
    		cnt = 0;
    	}
    }
    
    cout << res << endl;
    cout << tmp.fi << " " << tmp.se << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
