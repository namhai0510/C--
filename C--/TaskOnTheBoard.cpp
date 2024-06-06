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

ll test;
string s, ans;
char tmp;
ll n, b[maxn + 2];
vector<ll> pos, cur;
map<char, ll> mp;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> s;
    	s = '#' + s;
    	    	
    	cin >> n;
    	
    	pos.clear(); 
    	mp.clear();
    	tmp = 'z';
    	ans = " ";
    	for (int i = 1; i <= n; ++i) ans += " ";
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> b[i];
    		
    		if (b[i] == 0) pos.pb(i);
    	}
    	
    	for (int i = 1; i < s.size(); ++i) mp[s[i]]++;
    	
    	while (1) {
    		cur.clear();
    		
    		while (mp[tmp] < pos.size()) {
    			tmp--;
    		}
    		for (auto i : pos) ans[i] = tmp;
    		
    		bool ok = 0;
    		for (int i = 1; i <= n; ++i) if (b[i] > 0) ok = true;
    		if (!ok) break;
    		
    		tmp--;
    		
    		for (int i = 1; i <= n; ++i){
                if (b[i] != 0) {
                    for (auto j : pos) b[i] -= abs(i - j);
                    
                    if (b[i] == 0) cur.pb(i);
                }
            }
            pos = cur;
    	}
    	
    	for (int i = 1; i < ans.size(); ++i) cout << ans[i];
    	cout << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1367/D
