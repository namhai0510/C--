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

ll test, length = 0;
string t, deletion_order, ans, tmp, last;
map<char, ll> mp;
bool exist = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> t;
    	
    	mp.clear();
    	deletion_order = "";
    	ans = "";
    	tmp = "";
    	last = "";
    	
    	for (int i = t.size() - 1; i >= 0; --i) {
    		if (mp[t[i]] == 0) {
    			deletion_order = t[i] + deletion_order;
    		}
    		
    		mp[t[i]]++;
    	}
    	
    	// cout << deletion_order << endl;
    	
    	length = 0;
    	exist = 1;
    	
    	for (int i = 0; i < deletion_order.size(); ++i) {
    		if (mp[deletion_order[i]] % (i + 1) != 0) {
    			exist = 0;
    			break;
    		}
    		
    		mp[deletion_order[i]] /= (i + 1);
    		length += mp[deletion_order[i]];
    	}
    	
    	if (exist == 0) {
    		cout << -1 << endl;
    		continue;
    	}
    	
    	last = t.substr(0, length);
    	ans = last;
    	
    	int it = 0;
    	
    	while (last.size()) {
    		tmp += last;
    		
    		string x = "";
    		
    		for (int i = 0; i < last.size(); ++i) {
    			if (last[i] != deletion_order[it]) x += last[i];
    		}
    		
    		last = x;
    		it++;
    	}
    	
    	if (tmp == t) {
    		cout << ans << " " << deletion_order << endl;
    	}
    	else cout << -1 << endl;
    	
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1560/E