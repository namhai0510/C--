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

ll t, n, a[maxn + 2];
ll profit = 0, peak = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	
    	profit = 0; peak = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	for (int i = n; i >= 1; --i) {
    		if (a[i] > peak) peak = a[i];
    		
    		profit += peak - a[i];
    		
    		// cout << peak << " ";
    	}
    	
    	cout << profit << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/stockmax/problem?isFullScreen=true
