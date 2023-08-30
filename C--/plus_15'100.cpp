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

ll a, b;
vector<string> s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> a >> b;
    
    while (a != b) {
    	if (a % 2 == 0 && b % 2 == 0) {
    		a /= 2; b /= 2;
    	}
    	else if (a % 2 == 0 && b % 2 == 1) {
    		b += b;
    		a /= 2; b /= 2;
    		s.pb("B+=B");
    	}
    	else if (a % 2 == 1 && b % 2 == 0) {
    		a += a;
    		a /= 2; b /= 2;
    		s.pb("A+=A");
    	}
    	else {
    		if (a < b) {
    			a += a; b += a;
    			a /= 2; b /= 2;
    			s.pb("B+=A");
    			s.pb("A+=A");
    		}
    		else {
    			a += b; b += b;
    			a /= 2; b /= 2;
    			s.pb("A+=B");
    			s.pb("B+=B");
    		}
    	}
    }
    
    cout << s.size() << endl;
    for (auto it : s) cout << it << endl;
    return 0;
}