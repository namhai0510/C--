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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, m, p;
ll res[3], x;
bool ok = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> m >> p;
    
    ok = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> x;
    	
    	if (x % p && !ok) {
    		ok = 1;
    		res[1] = i;
    	}
    }
    
    ok = 0;
    for (int i = 1; i <= m; ++i) {
    	cin >> x;
    	
    	if (x % p && !ok) {
    		ok = 1;
    		res[2] = i;
    	}
    }
    
    cout << res[1] + res[2] - 2 << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1316/C
