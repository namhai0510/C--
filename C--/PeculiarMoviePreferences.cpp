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

ll test, n;
string s[maxn + 2];
unordered_map<string, ll> mp;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	bool exist = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> s[i];
    		mp[s[i]]++;
    		
    		if (exist) continue;
    		
    		if (s[i].size() == 1) {
    			exist = 1;
    		}
    		else if (s[i].size() == 2) {
    			string t = s[i];
    			reverse(t.begin(), t.end());
    			
    			if (mp[t] >= 1) {
    				exist = 1;
    				continue;
    			}
    			else {
    				for (char x = 'a'; x <= 'z'; ++ x) {
    					string f = t;
    					f = f + x;
    					if (mp[f] >= 1) {
    						// cout << 2 << " " << t << " " << f << endl;
    						exist = 1;
    						break;
    					}
    				}
    			}
    		}
    		else {
    			string t = s[i];
    			reverse(t.begin(), t.end());
    			
    			if (mp[t]) {
    				exist = 1;
    				continue;
    			}
    			else {
    				string f = t.substr(0, t.size() - 1);
    				if (mp[f] >= 1) {
    					// cout << 3 << " " << t << " " << f << endl;
    					exist = 1;
    				}
    			}
    		}
    	}
    	
    	if (exist) {    		
    		cout << "YES" << endl;
    	}
    	else 
    		cout << "NO" << endl;
    	
    	for (int i = 1; i <= n; ++i) mp[s[i]]--;
    }
    return 0;
}
