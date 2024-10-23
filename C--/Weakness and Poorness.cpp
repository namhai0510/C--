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

ll n, a[maxn + 2];
double b[maxn + 2];
double l, r, midl, midr;

double Calc(double x) {
	for (int i = 1; i <= n; ++i) b[i] = a[i] - x;
	
	double ret[2], tmp;
	ret[0] = ret[1] = 0.0;
	
	tmp = 0.0;
	for (int i = 1; i <= n; ++i) {
		tmp += b[i];
		
		if (tmp < 0) tmp = 0;
		ret[0] = max(ret[0], tmp);
	}
	
	for (int i = 1; i <= n; ++i) b[i] = (-b[i]);
	
	tmp = 0.0;
	for (int i = 1; i <= n; ++i) {
		tmp += b[i];
		
		if (tmp < 0) tmp = 0;
		ret[1] = max(ret[1], tmp);
	}
	
	return max(ret[0], ret[1]);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    l = -1e4;
    r = +1e4;
    
    for (int i = 1; i <= 100; ++i) {
    	midl = (2 * l + r) / 3.0;
    	midr = (2 * r + l) / 3.0;
    	
    	if (Calc(midl) < Calc(midr)) r = midr;
    	else l = midl;
    }
    
    cout << fixed << setprecision(12) << Calc(r) << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/578/C
