#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll n, x, a[maxn + 2];
ll cnt = 0, ans = 0, dp[256][256];
pair<ll, ll> f[maxn + 2];

int main() {
    nothing
    if (fopen("div10x.inp", "r")) {
        freopen("div10x.inp", "r", stdin);
        freopen("div10x.out", "w", stdout);
    }
    cin >> n >> x;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	cnt = 0;
    	while (a[i] % 5 == 0) {
    		a[i] /= 5;
    		cnt++;
    	}
    	
    	f[i].fi = cnt;
    	
    	cnt = 0;
    	while (a[i] % 2 == 0) {
    		a[i] /= 2;
    		cnt++;
    	}
    	
    	f[i].se = cnt;
    }
	sort(f + 1, f + 1 + n);
	reverse(f + 1, f + 1 + n);
	
	for (int j = 0; j <= 30; ++j) {
    	for (int k = 0; k <= 70; ++k) {
    		dp[j][k] = +oo;
    		// cout << dp[j][k] << endl;
    	}
    }
    dp[0][0] = 0;
    
	for (int i = 1; i <= n; ++i) {
		for (int j = 30; j >= 0; --j) {
			for (int k = 70; k >= 0; --k) {
				if (j >= f[i].fi && k >= f[i].se)
					dp[j][k] = min(dp[j][k], dp[j - f[i].fi][k - f[i].se] + 1);
			}
		}
	}
    
    ans = +oo;
    
    for (int j = x; j <= 30; ++j) {
    	for (int k = x; k <= 70; ++k) {
    		ans = min(ans, dp[j][k]);
    		// cout << dp[j][k] << endl;
    	}
    }
    
    cout << ans << endl;
    return 0;
}

// In ra so luong phan tu it nhat ma co tich chia het cho 10^x
