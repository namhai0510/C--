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

ll test, a, b, x, y;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> a >> b;
    	
    	if (a == 0) {
    		x = 0;
    		y = 1;
    	}
    	else if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
    		a = abs(a);
    		b = abs(b);
    		
    		x = a / __gcd(a, b);
    		y = b / __gcd(a, b);
    	}
    	else {
    		ll tmpX, tmpY;
    		tmpX = a / __gcd(abs(a), abs(b));
    		tmpY = b / __gcd(abs(a), abs(b));
    		
    		if (tmpX + tmpY > 0) x = tmpX, y = tmpY;
    		else if (tmpX + tmpY < 0) x = -tmpX, y = -tmpY;
    		else x = 0, y = 0;
    	}
    	
    	cout << x << " " << y << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r18_a
