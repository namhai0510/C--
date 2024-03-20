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

ll n, nxt, controller, stowaway, t = 0;
string s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> stowaway >> controller;
    
    getline(cin, s);
    getline(cin, s);
    
    if (s == "to head") nxt = -1;
    else nxt = +1;
    
    // head : 1
    // tail : n
    
    cin >> s;
    
    s = '#' + s;
    
    for (int i = 1; i <= s.size() - 1; ++i) {
    	++t;
    	
    	if (controller == 1) nxt = +1;
    	if (controller == n) nxt = -1;
    	
    	if (s[i] == '1') {
    		stowaway = controller;
    	}
    	
    	controller += nxt;
    	
    	if (stowaway == controller) stowaway += nxt;
    	
    	if (stowaway == 0 || stowaway == n + 1) {
    		cout << "Controller" << " " << t << endl;
    		return 0;
    	}
    }
    
    cout << "Stowaway" << endl;
    return 0;
}
