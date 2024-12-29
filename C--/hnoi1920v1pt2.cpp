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

// ll nhan(ll a, ll b, ll mod) {
    // if (b == 0)  return 0;
    // ll t = nhan(a, b / 2, mod);      
    // t = (t + t) % mod; 
    // if (b % 2 == 1) 
        // t = (t + a) % mod;
    // return t;
// } 
// 
// ll power(ll a, ll b, ll mod) {
    // if (b == 0) 
        // return 1;
    // ll t = power(a, b / 2, mod);         
    // t = nhan(t, t, mod);
    // if (b % 2 == 1) 
        // t = nhan(t, a, mod);
    // return t;
// } 
// 
ll a, b, k;
ll x, c;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b >> k;
    
    k -= 10;
    x = 10;
    c = 1;
    
    while (1) {
    	x *= 10;
    	
		if ((a * x + b) % k == 0) {
			cout << (ll)(a * pow(10, c + 1) + b) / k;
			exit(0);
		} 
		
		c++;
    }
        
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
