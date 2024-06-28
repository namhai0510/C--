#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e21;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

struct Data {
	ll a, v;
};

Data x[maxn + 2];
ll n;
double res = +oo;

double Calc(double val) {
	double lst = +oo, fir = -oo, pos;
	
	for (int i = 1; i <= n; ++i) {
		pos = val * x[i].v + x[i].a;
		
		lst = min(lst, pos);
		fir = max(fir, pos);
	}
	
	return fir - lst;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> x[i].a;
    for (int i = 1; i <= n; ++i) cin >> x[i].v;
    
    double l = 0, r = +oo;
    
    for (int step = 1; step <= 1000; ++step) {
		double L = l + (r - l) / 3, LL = Calc(L);
		double R = r - (r - l) / 3, RR = Calc(R);
		
		res = min({res, LL, RR});
		if (LL < RR) r = R; 
		else l = L;
    }
    
    cout << fixed << setprecision(3) << res / 2.0 << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/c11ant