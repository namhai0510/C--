#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

map<ll, ll> st, en;
ll n, a[maxn + 2], psum[maxn + 2], ans = -1;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    	if (st[a[i]] == 0) st[a[i]] = i;
    	if (st[a[i]] != 0) en[a[i]] = i;
    }
    
    for (auto it : en) {
    	ans = max(ans, psum[it.se] - psum[st[it.fi] - 1]);
    }
    cout << ans;
}