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
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll a, b, n;
ll dp[maxn + 2];
ll ans = 0, s = 0;

void Process() {
	for (int i = 0; i <= maxn; ++i) dp[i] = 1;
	for (int i = 1; i <= maxn; ++i) dp[i] = dp[i - 1] * i % modd;	
	
	for (int i = 0; i <= n; ++i) {
		s = a * i + b * (n - i);
		
		ll x = s;
		bool valid = 1;
		
		while (x) {
			int d = x % 10;
			if (d != a && d != b) {
				valid = 0;
				break;
			}
			
			x /= 10;
		}
		
		if (valid) {
			ll up = dp[n] % modd;
            ll down = (dp[i] * dp[n - i]) % modd;
            ll r = 1;
            ll x = down, y = modd - 2;

            // Tính r = down ^ (mod - 2) % modd bằng cách lũy thừa nhị phân
            while (y) {
                if (y & 1) {
                    r = (r * x) % modd;
                }
                
                y >>= 1;
                x = (x * x) % modd;
            }

            r = (up * r) % modd;
            ans = (ans + r) % modd;
		}
	}
	
	cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b >> n;
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/300/C
