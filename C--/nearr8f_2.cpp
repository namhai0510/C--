#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    // (i - 1) * n + j
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		ll v = m - i + 1;
    		
    		if (j <= n / 2) {
    			ll res = j * 2 - (j % 2) - 1;
    			if (res % 2 == 0) cout << res * m + v << " ";
                else cout << res * m + i << " ";
    		}
    		else if (n % 2 == 1 && j == (n + 1) / 2){
                cout << (n - 1) * m + v << " ";
            }
            else {
                ll res = (n - j + 1) * 2 - ((n - j + 1) % 2);
                if (res % 2 == 0) cout << (res - 2) * m + v << " ";
                else cout << res * m + i << " ";
            }
    	}
    	cout << endl;
    }
	
    return 0;
}
