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

ll n;
string s, t;

ll dr = 0, fir = 0, sec = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    cin >> s >> t;
    
    s = '#' + s;
    t = '#' + t;
    
    for (int i = 1; i <= 2 * n; ++i) {
    	if (s[i] == t[i] && t[i] == '1') {
    		dr++;
    	}
    	else if (s[i] == '1') {
    		fir++;
    	}
    	else if (t[i] == '1') {
    		sec++;
    	}
    }
    
    fir += (dr % 2);
    
    if (fir > sec) cout << "First" << endl;
    else if (sec > fir + 1) cout << "Second" << endl;
    else cout << "Draw" << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/293/A
