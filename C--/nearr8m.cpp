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

ll a[maxn + 2], n, res = 1;
ll su, eu, sr, er, sl, el, sd, ed;
bool ok = false;

int main() {
    nothing
    if (fopen("nearr8m.inp", "r")) {
        freopen("nearr8m.inp", "r", stdin);
        freopen("nearr8m.out", "w", stdout);
    }
    cin >> n;
    
    su = (n - 1) / 2 + 1;
    eu = n / 2 + 1;
    sr = su + (n % 2 == 0);
    er = eu + (n % 2 == 1);
    sl = su; sd = su + 1;
    el = eu - 1; ed = eu - (n % 2 == 0);
    
    while (n >= eu && n >= sr && 1 <= sl && 1 <= ed) {
    	for (int i = su; i >= 1; --i) {
    		a[(i - 1) * n + eu] = res;
    		++res;
    	}
    	
    	++eu;
    	
    	if (n % 2 == 1 && ok == false) {
    		--su;
    		ok = true;
    	}
    	
    	for (int i = er; i <= n; ++i) {
    		a[(sr - 1) * n + i] = res;
    		++res;
    	}
    	
    	++sr;
    	
    	for (int i = sd; i <= n; ++i) {
    		a[(i - 1) * n + ed] = res;
    		++res;
    	}
    	
    	--ed;
    	
    	for (int i = el; i >= 1; --i) {
    		a[(sl - 1) * n + i] = res;
    		++res;
    	}
    	
    	--sl;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cout << a[(i - 1) * n + j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}
