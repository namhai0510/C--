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

double a, b, c, d;
ll cP = 0, cN = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b >> c >> d;
    
    if (a == 0.0 || b == 0.0 || c == 0.0 || d == 0.0) cout << 0 << endl;
    else {
    	if (a < 0.0) cN++;
    	else cP++;
    	
    	if (b < 0.0) cN++;
    	else cP++;
    	
    	if (c < 0.0) cN++;
    	else cP++;
    	
    	if (d < 0.0) cN++;
    	else cP++;
    	
    	if (cN % 2 == 0) cout << 1 << endl;
    	else cout << -1 << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
