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

ll n, a[maxn + 2];
ll cnt = 0, tmp;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	if (a[i] == 1) cnt++;
    	
    	tmp = a[i];
    	for (int j = 2; j <= sqrt(tmp); ++j)
    		if (tmp % j == 0 && tmp / j != j) {
    			cnt++;
    			break;
    		}
    }
    
    cout << cnt << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
