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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, ans = 1, cnt = 0;

ll mul (ll a, ll b) {
    if (b == 0) return 0;
    
    ll t = mul (a, b / 2);
    t = (t + t) % modd;
    
    if (b % 2 == 1) t = (t + a) % modd;
    
    return t;
}

bool check () {
    if (n <= 1) return 0;
    
    for (int i = 2; i * i <= n; ++i) 
        if (n % i == 0) return 0;
    
    return 1;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    while (1) {
    	if (cnt == 5) break;
    	
    	if (check()) {
    		ans = mul(ans, n);
    		cnt++;
    	}
    	
    	n++;
    }
    
    cout << ans << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
