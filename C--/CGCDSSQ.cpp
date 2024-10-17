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

ll n, q;
ll a[maxn + 2];
map<ll, ll> Div, nxtDiv, res;

ll GCD(ll a, ll b) {
	if (a < b) swap(a, b);
	
	if (a % b == 0) return b;
	
	return (b, a % b);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
    	nxtDiv.clear();
    	
    	for (auto p : Div)
    		nxtDiv[GCD(p.fi, a[i])] += p.se;
    	
    	nxtDiv[a[i]]++;
    	
    	swap(Div, nxtDiv);
    	for (auto p : Div) 
    		res[p.fi] += p.se;
    		
    	// for (auto p : Div) cout << p.fi << " " << p.se << endl;
    	// cout << "----" << endl;
    }
    
    for (auto p : res) cout << p.fi << " " << p.se << endl;
    
    cin >> q;
    
    while (q--) {
    	int x; cin >> x;
    	
    	cout << res[x] << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/475/D
