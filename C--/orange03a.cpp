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

ll n, k, d, a[maxn + 2];
ll mina = 0, ans, cnt;
int main() {
    nothing
    if (fopen("orange03a.inp", "r")) {
        freopen("orange03a.inp", "r", stdin);
        freopen("orange03a.out", "w", stdout);
    }
    cin >> n >> k >> d;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);
    
    mina = 0; ans = 0; cnt = d;
    
    for (int i = 1; i <= n; ++i) {
    	if (a[i] - mina > k || cnt == d) {
    		ans++;
    		mina = a[i];
    		cnt = 1;
    	}
    	else cnt++;
    }
    
    cout << ans << endl;
    return 0;
}
