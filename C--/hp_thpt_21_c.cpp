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

ll n, k, a[maxn + 2];
unordered_map<ll, ll> pos;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    pos[a[1]] = 1; 
    for (int i = 2; i <= n; ++i) {
    	if (pos[2 * k - a[i]] != 0) {
    		cout << pos[2 * k - a[i]] << " " << i << endl;
    		return 0;
    	}
    	
    	pos[a[i]] = i;
    }
    
    cout << 0 << " " << 0 << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hp_thpt_21_c
