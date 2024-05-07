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

struct Data {
	ll x, y;
};

ll t, n, k;
Data st, en, sum[maxn + 2], tmp, dif;
string s;

bool ok = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
	    cin >> n >> k;
	    cin >> st.x >> st.y >> en.x >> en.y;
	    cin >> s;
	    
	    s = '#' + s;
	    
	    ok = 0;
	    
	    for (int i = 1; i <= n; ++i) {
	    	sum[i].x = sum[i - 1].x + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
	    	sum[i].y = sum[i - 1].y + (s[i] == 'U' ? -1 : (s[i] == 'D' ? 1 : 0));
	    }
	    
	    dif.x = en.x - st.x; 
	    dif.y = en.y - st.y;
	
	    for (ll l = 1, r = k; r <= n; l++, r++) {
	        tmp.x = sum[l - 1].x + (sum[n].x - sum[r - 1].x);
	        tmp.y = sum[l - 1].y + (sum[n].y - sum[r - 1].y);
	        
	        if (abs(dif.x - tmp.x) + abs(dif.y - tmp.y) <= k) {
	        	ok = 1;
	        	break;
	        }
	    }
	    
	    if (!ok) cout << "NO" << endl;
	    else cout << "YES" << endl;
    }
    
    
    return 0;
}

// https://oj.vnoi.info/problem/bedao_m24_b
