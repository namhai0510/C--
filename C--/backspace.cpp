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

ll q, m, n;
string s, t;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> q;
    
    while (q--) {
    	cin >> s >> t;
    	
    	m = s.size(); n = t.size();
    	s = '#' + s;
    	t = '#' + t;
    	
    	if (m < n) {
    		cout << "NO" << endl;
    		continue;
    	}
    	
    	int i = m, j = n;
    	
    	while (i >= 1 && j >= 1) {
    		if (s[i] != t[j]) i -= 2;
    		else {
    			--i;
    			--j;
    		}
    	}
    	
    	if (j < 1) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1553/D