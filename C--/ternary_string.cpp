#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, c[4];
string s;

int main() {
    nothing
    if (fopen("ternary_string.inp", "r")) {
        freopen("ternary_string.inp", "r", stdin);
        freopen("ternary_string.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> s;
    	c[1] = 0; c[2] = 0; c[3] = 0;
    	s = '#' + s;
    	
    	ll st = 1, en = 0, ans = +oo;
    	for (st = 1; st < s.size(); ++st) {
    		while ((c[1] < 1 || c[2] < 1 || c[3] < 1) && en < s.size() - 1) {
	    		en++;
	    		c[s[en] - '0']++;
	    	}
	    	
	    	if (c[1] >= 1 && c[2] >= 1 && c[3] >= 1) {
	    		ans = min(ans, en - st + 1);
	    		// cout << st << " " << en << " " << endl;
	    	}
	    	
	    	c[s[st] - '0']--;
	    	// cout << st << " " << en << " " << c[1] << " " << c[2] << " " << c[3] << endl;
    	}
    	
    	if (ans == +oo) cout << 0 << endl;
    	else cout << ans << endl;
    	// cout << "-------------" << endl;
    }
    
    return 0;
}