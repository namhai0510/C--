#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 2e9;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, a[maxn + 2];
ll dp[maxn + 2], pos[maxn + 2], res = 0;

vector<ll> LIS;

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
    
    for (int i = 1; i <= n; ++i) {
    	dp[i] = +oo;
    	pos[i] = lower_bound(dp + 1, dp + 1 + res, a[i]) - dp;
    	res = max(res, pos[i] + 1);
    	
    	dp[pos[i]] = a[i];
    }
    
    res--;
    
    for (int i = n; i >= 1; --i) {
    	if (pos[i] == res) LIS.pb(a[i]), res--;
    }
    
    reverse(LIS.begin(), LIS.end());
    
    cout << LIS.size() << endl;
    for (auto val : LIS) cout << val << " ";
    
    return 0;
}
