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

ll n, height[maxn + 2], ans = 0;
vector<ll> child[maxn + 2];
map<ll, ll> cnt;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    height[1] = 1;
    for (int i = 2; i <= n; ++i) {
    	ll x; cin >> x;
    	child[x].pb(i);
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (auto it : child[i]) {
    		height[it] = height[i] + 1;
    	}
    }
    
    for (int i = 1; i <= n; ++i) {
    	// cout << height[i] << " ";
    	cnt[height[i]]++;
    }
    
    for (auto it : cnt) {
    	ans += it.se % 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
