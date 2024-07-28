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

ll n, q, a[maxn + 2];

ll Process(ll l, ll r) {
    unordered_set<ll> s;
    for (int i = l; i <= r; ++i) s.insert(a[i]);
    
    for (int i = 0; i <= r; ++i)
        if (s.find(i) == s.end()) return i;
    
    return r; 
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    while (q--) {
    	ll l, r;
    	cin >> l >> r;
    	
    	cout << Process(l, r) << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
