#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const double epsilon = 0.000000000000000001;
const ll oo = 1e13;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

double P, V, T;
double R = 0.0821;
double E, n;

int main() {
    nothing
    if (fopen("SMK.inp", "r")) {
        freopen("SMK.inp", "r", stdin);
        freopen("SMK.out", "w", stdout);
    }
	
	cin >> P >> V >> T;
	
	n = (P / T) * (V / R);
	if (n > 5 + epsilon) cout << "Qua tai" << endl;
	else {
		E = P * V * 2 / 3.0;
		
		cout << setprecision(3) << E << endl;
	}
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
