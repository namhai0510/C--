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

ll n, s = 0, ans = 0,
	a[maxn + 2], ps[maxn + 2];

int main() {
    nothing
    if (fopen("number_of_ways.inp", "r")) {
        freopen("number_of_ways.inp", "r", stdin);
        freopen("number_of_ways.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	s += a[i];
    	ps[i] = ps[i - 1] + a[i];
    }
    
    if (s % 3 != 0) {
    	cout << 0;
    	return 0;
    }
    
    ll c = 0;
    for (int i = 1; i <= n; ++i) {
    	if (ps[i] * 3 == 2 * s) ans += c;
    	if (ps[i] * 3 == s) c++;
    }
    
    if (s == 0) ans -= c - 1;
    cout << ans;
    return 0;
}

// https://codeforces.com/problemset/problem/466/C
