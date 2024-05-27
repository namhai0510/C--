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
const int base = 31;

ll test, exist = 0;
ll A, B, X, Y;
ll C = 0, D = -1;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    while (test--) {
    	exist = 0;
	    cin >> A >> B >> X >> Y;
	    
	    for(int C = 0; C <= 10000; ++C) {

        	if (((A + C) * X) % Y != 0) continue;

	        int D = ((A + C) * X) / Y - B;
	
	        if (D >= 0) {
	        	exist = 1;
	            cout << C + D << "\n";
	            break;
	        }
	    }
	    
	    if (!exist) cout << -1 << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m21_a
