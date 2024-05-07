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

ll q, d = 0;
vector<pair<ll, ll>> ans;
multiset<pair<ll, ll>> m;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    int id = 0;
    
    cin >> q;
    
    for (int i = 1; i <= q; ++i) {
    	ll type, val;
    	cin >> type >> val;
    	
    	if (type == 1) {
    		id++;
    		m.insert({val - d, id});
    	}
    	else if (type == 2) {
    		d += val;
    	}
    	else {
    		while (1) {
    			auto it = m.lower_bound({val - d, 0});
    			if (it == m.end() || it->fi > val - d) break;
    			
    			m.erase(it);
    		}
    	}
    }
    
    for (auto it : m) {
    	ans.pb({it.se, it.fi});
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (auto it : ans) {
    	cout << it.se + d << " ";
    }
    
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m24_c
