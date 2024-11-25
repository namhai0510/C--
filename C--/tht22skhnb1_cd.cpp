#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll a[4];
ll res[4];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> a[1] >> a[2] >> a[3];
	
	sort(a + 1, a + 1 + 3);
	res[1] = a[1];
	res[2] = a[2];
	res[3] = a[3];
	
	if (a[1] == a[2] && a[2] == a[3] && a[1] == 0) {
		cout << -1 << endl;
		return 0;
	}
	
	do {
		// cout << a[1] << " " << a[2] << " " << a[3] << endl;
		if (a[3] == 0) continue;
		
		if (a[1] < res[1]) continue;
		
		if (a[1] > res[1]) {
			res[1] = a[1];
			res[2] = a[2];
			res[3] = a[3];
		}
		else {
			if (a[2] * res[3] >= res[2] * a[3] && (a[2] * a[3] > 0)) {
				res[2] = a[2];
				res[3] = a[3];
			}
			else if (a[2] * res[3] < res[2] * a[3] && (a[2] * a[3] < 0)) {
				res[2] = a[2];
				res[3] = a[3];
			}
		}		
	}
	while (next_permutation(a + 1, a + 1 + 3));
	
	cout << res[1] << " " << res[2] << " " << res[3] << endl;
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.codedream.edu.vn/problem/tht22skhnb1