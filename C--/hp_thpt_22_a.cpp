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

string s;
ll n, cnt = 0;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    
    n = s.size();
    s = '#' + s;
    
    int pos = 1;
    
    while (pos <= n - 5 + 1) {
    	if (s[pos] == 'v')
    		if (s[pos + 1] == 'i')
    			if (s[pos + 2] == 'r')
    				if (s[pos + 3] == 'u')
    					if (s[pos + 4] == 's') {
    						pos = pos + 5;
    						cnt++;
    						continue;
    					}
    	
    	pos++;
    }
    
    cout << cnt << endl;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/hp_thpt_22_a
