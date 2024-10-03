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

ll n, a, b, c, ab, bc, ca, abc;

ll GCD(ll x, ll y) {
    while (y != 0) {
        ll r = x % y;
        x = y;
        y = r;
    }
    
    return x;
}

ll LCM(ll x, ll y) {
	if (x == -1 || y == -1) return -1;
    ll g = GCD(x, y);

    if (y / g > n / x) return -1;

    return (x / g) * y;
}

ll GET(ll m, ll q) {
	if (q == -1) return 0;
	
	if (m % q != 0) return 0;
	
	ll mm = m / q, res = 0;
	
	for (ll i = 1; i * i <= mm; ++i)
        if (mm % i == 0) 
            if (i * i == mm) {
            	res++;
            }
            else res += 2;
    
    return res;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> a >> b >> c;
    
    ab = LCM(a, b);
    bc = LCM(b, c);
    ca = LCM(c, a);
    abc = LCM(LCM(a, b), c);
    
    cout << GET(n, ab) + GET(n, bc) + GET(n, ca) - 2 * GET(n, abc);
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
