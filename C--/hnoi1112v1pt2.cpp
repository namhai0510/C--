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
const int maxn = 2e5;
const int maxa = 2e3;
const int base = 31;

ll n, a[maxn + 2];
char s[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= 2 * n; ++i) s[i] = '#';
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= 2 * n; ++j) {
    		if (s[j] == '#') {
    			s[j] = '(';
    			s[j + a[i] + 1] = ')';
    			break;
    		}
    	}
    }
    
    for (int i = 1; i <= 2 * n; ++i) cout << s[i];
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
