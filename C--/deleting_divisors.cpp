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

ll t, n, cnt = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	if (n % 2 == 1) {
    		cout << "Bob" << endl;
    		continue;
    	}
    	
    	cnt = 0;
    	while (n % 2 == 0) {
    		cnt++;
    		n /= 2;
    	}
    	
    	if (n > 1) cout << "Alice" << endl;
    	else if (cnt % 2 == 0) cout << "Alice" << endl;
    	else cout << "Bob" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1537/D
