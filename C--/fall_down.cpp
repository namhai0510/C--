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

ll t, m, n;
char a[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> m >> n;
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			cin >> a[(i - 1) * n + j];
    		}
    	}
    	
    	for (int j = 1; j <= n; ++j) {
			int last = m;
			for (int i = m; i >= 1; --i) {
				if (a[(i - 1) * n + j] == 'o') last = i - 1;
				else if (a[(i - 1) * n + j] == '*') {
					swap(a[(i - 1) * n + j], a[(last - 1) * n + j]); 
					--last;
				}
			}
		}
		
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) cout << a[(i - 1) * n + j];
			cout << endl; 
		}
		
		cout << endl;
    }
    return 0;
}
