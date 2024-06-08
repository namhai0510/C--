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

ll test, n, a[maxn + 2];
ll S, maxA;

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
    	maxA = -200;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		S += a[i];
    		maxA = max(maxA, a[i]);
    	}
    	
    	if (maxA * 2 > S || (S % 2 == 1)) cout << "T" << endl;
    	else cout << "HL" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1396/B