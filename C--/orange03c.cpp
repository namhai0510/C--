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

ll n, step = 0, ans = 1;
map<ll, ll> mark;

int main() {
    nothing
    if (fopen("orange03c.inp", "r")) {
        freopen("orange03c.inp", "r", stdin);
        freopen("orange03c.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 2; i * i <= n; ++i) {
    	ll cnt = 0;
    	
    	while (n % i == 0) {
    		n /= i;
    		cnt++;
    	}
    	
    	if (cnt > 0) mark[i] = cnt;
    }
    
    if (n > 1) mark[n]++;
    
    for (int i = 2; i <= maxa; ++i) {
    	if (mark[i] > 0) {
    		ans *= i;
    		step += (mark[i] - 1) / 3 + 1 - (mark[i] % 3 == 0);
    	}
    }
    
    cout << ans << " " << step << endl;
    return 0;
}
