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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, k, all, ans = -1;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    all = k * (k + 1) / 2;
    ll l = 1, r = k, mid;
    
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	ll pipes = all - mid * (mid + 1) / 2 - (k - mid - 1);
    	
    	if (pipes >= n) l = mid + 1, ans = k - mid;
    	else r = mid - 1;
    }
    
    cout << ans << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/287/B