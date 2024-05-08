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

ll n, t;
string s;
bool ctn = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
	    cin >> s;
	    
	    ctn = 0;
	    n = s.size();
	    s = '#' + s;
	    
	    if (n <= 1) {
	    	cout << -1 << endl;
	    	continue;
	    }
	    
	    for (int i = 1; i <= n - 1; ++i) {
	    	if (s[i] == s[i + 1] || s[i] == s[i + 2]) {
	    		cout << 0 << endl;
	    		ctn = 1;
	    		break;
	    	}
	    }
	    
	    if (ctn) continue;
	    
	    cout << 1 << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m23_a
