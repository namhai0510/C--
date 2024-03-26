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

ll n, a[maxn + 2];

ll dp[maxn + 2], S = 0, ps[maxn + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	ps[i] = ps[i - 1] + a[i];
    	S += a[i] * i;
    }
    
    ans = S;
    
    for (int i = 1; i <= n; ++i) {
    	ans = max({ans, S - a[i] * i + (ps[i - 1] + a[i]), S - (a[i] * i + ps[n] - ps[i]) + a[i] * n});
    }
    
    cout << ans << endl;
    
    return 0;
}
