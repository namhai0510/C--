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
const int base = 31;

ll n, a[maxn + 2];
ll l[maxn + 2], r[maxn + 2], length, ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    l[1] = r[n] = 0;
    
    length = 0;
    
    for (int i = 2; i <= n; ++i) {
    	if (a[i] > a[i - 1]) {
    		length++;
    		l[i] = length;
    	}
    	else {
    		length = 0;
    		l[i] = 0;
    	}
    }
    
    length = 0;
    
    for (int i = n - 1; i >= 1; --i) {
    	if (a[i] > a[i + 1]) {
    		length++;
    		r[i] = length;
    	}
    	else {
    		length = 0;
    		r[i] = 0;
    	}
    }
    
    // for (int i = 1; i <= n; ++i) cout << l[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; ++i) cout << r[i] << " ";
    // cout << endl;
    
    for (int i = 1; i <= n; ++i) 
    	ans += (l[i] + 1) * (r[i] + 1);
    	
    cout << ans << endl;
    return 0;
}
