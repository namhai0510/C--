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

ll a, b, c;
ll cnt = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b >> c;
    
    for (int y = 1; y <= max((c / b) - 1, 0LL); ++y) {
    	int x;
    	
    	if ((c - y * b) % a == 0) x = (c - y * b) / a;
    	else continue;
    	
    	// cout << x << " " << y << endl;
    	
    	if (__gcd(x, y) == 1) cnt++;
    }
    
    cout << cnt << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
