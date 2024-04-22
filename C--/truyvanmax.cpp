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

ll n, q, a[maxn + 2];
ll f[maxn + 2], mx = 0, tmp, ans = 0;

void Sub1 () {
	for (int test = 1; test <= q; ++ test) {
    	tmp = -oo;
    	ll i, s;
    	cin >> i >> s;
    	
    	for (int j = 1; j <= n; ++j) {
    		if (i % j == 0) tmp = max(tmp, f[j] + s);
    		else tmp = max(tmp, f[j]);
    	}
    	
    	ans += tmp;
    }
    
    cout << ans << endl;
}

void Sub2() {
	for (int test = 1; test <= q; ++test) {
    	tmp = -oo;
    	ll i, s;
    	cin >> i >> s;
    	
    	for (int j = 1; j * j <= i; ++j) {
    		if (i % j == 0) {
    			tmp = max(tmp, f[j] + s);
    			
    			if (j != (i / j)) tmp = max(tmp, f[i / j] + s);
    		}
    	}
    	
    	// tmp la gtri lon nhat trong nhung f[k] thay doi
    	ans += max(mx, tmp);
    }
    
    cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	f[i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j * j <= i; ++j) {
    		if (i % j == 0) {
    			f[j] += a[i];
    			
    			if (j != (i / j)) f[i / j] += a[i];
    		}
    	}
    }
    
    for (int i = 1; i <= n; ++i) {
    	// cout << f[i] << endl;
    	mx = max(mx, f[i]);
    }
    
    cin >> q;
    
    if (n <= 5000 && q <= 5000) Sub1();
    else Sub2();
    
    
    return 0;
}
