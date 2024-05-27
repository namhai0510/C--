#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 6e18;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll test, v, k;
ll val[] = {-1, 2, 3, 5, 7};

ll Solve(ll f) {
	ll tmp = 0, prod = 1;
	
	for (int x = 0; x < (1 << 4); ++x) {
		prod = 1;
		for (int i = 0; i < 4; ++i) {
			if ((x >> i) & 1) prod *= val[i + 1];
		}
		
		tmp += f * (__builtin_popcount(x) & 1 ? -1 : 1) / prod;
	}
	
	return tmp;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> v >> k;
    	
    	ll l = 1, r = +oo, mid;
    	while (l < r) {
    		mid = (l + r) >> 1;
    		
    		if (Solve(mid) >= k) r = mid;
    		else l = mid + 1;
    	}
    	
    	cout << Solve(v) << " " << l << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m23_c
