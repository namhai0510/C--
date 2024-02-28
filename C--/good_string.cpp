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

ll t, ans = 0;
string s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> s;
    	ans = 0;
    	int n = s.size();
    	for (int i = 0; i <= 9; ++i) {
    		for (int j = 0; j <= 9; ++j) {
    			ll res = 0, x = i, y = j;
    			
    			for (int pos = 0; pos < n; ++pos) {
    				// cout << s[pos] << endl;
    				// cout << s[pos] - '0' << endl;
    				if (s[pos] - '0' == x) {
    					res++;
    					swap(x, y);
    				}
    			}
    			
    			if (x != y && res % 2 == 1) res--;
    			
    			ans = max(ans, res);
    		}
    	}
    	
    	cout << s.size() - ans << endl;
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1389/C