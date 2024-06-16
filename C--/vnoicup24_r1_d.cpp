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

ll test, n, x[maxn + 2];
ll S = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	S = 0;
    	
    	for (int i = 1; i <= n; ++i) cin >> x[i];
    	for (int i = 2; i <= n; ++i)
    		S += x[i] * (i - 1) * (n - i + 1) - x[i - 1] * (i - 1) * (n - i + 1);
    		
    	cout << fixed << setprecision(100) << S / 2.0 << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/vnoicup24_r1_d
