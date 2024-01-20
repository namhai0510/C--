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

ll w, h, c = 0;
char a[maxa + 2][maxa + 2];
vector<pair<ll, ll>> it;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> w >> h;
    for (int i = 0; i <= maxa; ++i) {
    	for (int j = 0; j <= maxa; ++j) a[i][j] = '.';
    }
    
    for (int i = 1; i <= w; ++i) {
    	for (int j = 1; j <= h; ++j) {
    		cin >> a[i][j];
    		if (a[i][j] == '*') {
    			c++;
    		}
    	}
    }
    
    for (int i = 1; i <= w; ++i) {
    	for (int j = 1; j <= h; ++j) {
    		if (a[i][j] == '*'
    			&& a[i - 1][j] == '*'
    			&& a[i + 1][j] == '*'
    			&& a[i][j - 1] == '*'
    			&& a[i][j + 1] == '*')
    				it.pb({i, j});
    	}
    }
    
    for (auto t : it) {
    	ll u = t.fi, v = t.se, cur = 1;
    	
    	// cout << u << " " << v << endl;
    	
    	for (int i = u + 1; i <= w; ++i) {
    		if (a[i][v] == '*') {
    			cur++;
    		}
    		else break;
    	}
    	for (int i = u - 1; i >= 1; --i) {
    		if (a[i][v] == '*') {
    			cur++;
    		}
    		else break;
    	}
    	for (int j = v + 1; j <= h; ++j) {
    		if (a[u][j] == '*') {
    			cur++;
    		}
    		else break;
    	}
    	for (int j = v - 1; j >= 1; --j) {
    		if (a[u][j] == '*') {
    			cur++;
    		}
    		else break;
    	}
    	
    	if (cur == c) {
    		cout << "YES";
    		return 0;
    	}
    }
    
    cout << "NO";
    return 0;
}

// https://codeforces.com/problemset/problem/1182/B