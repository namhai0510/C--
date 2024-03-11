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

ll q, ps[maxn + 2], a[maxn + 2];

ll Calc(ll x) {
	ll res = 0;
	while(x > 0){
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
    nothing
    if (fopen("slr.inp", "r")) {
        freopen("slr.inp", "r", stdin);
        freopen("slr.out", "w", stdout);
    }
    
    for (int i = 1; i <= maxn; ++i) {
    	ll val = Calc(i);
    	
    	if (val < 10) a[i] = val;
    	else a[i] = a[val];
    	
    	ps[i] = ps[i - 1] + a[i];
    }
    
    cin >> q;
    
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	cout << ps[r] - ps[l - 1] << endl;
    } 
    return 0;
}
