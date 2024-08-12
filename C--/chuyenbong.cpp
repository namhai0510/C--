#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

ll n, m, q;
ll x, y;
ll p[maxn + 2];
ll ans, res, tmp, nwx;

set<ll> s[3];
void Input() {
	cin >> n >> m >> q;
	
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
		
		s[1].insert(p[i]);
		s[2].insert(p[i] + n);
	}
}

void Process() {
	while (q--) {
		cin >> x >> y;
		
		ans = min(abs(x - y),2 * n - abs(x - y));
        if (x < n) {
            auto it = s[1].lower_bound(x);
            
            if (it != s[1].end()){
	            tmp = *it;
                nwx = tmp + n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            else {
                auto it1 = s[2].begin(); 
                tmp = *it1;
                nwx = tmp - n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            
            if (it != s[1].begin()) {
                it--;
                tmp = *it;
                nwx = tmp + n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
            	res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            else {
                auto it1 = s[2].rbegin(); 
                tmp = *it1;
                nwx = tmp - n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
        }
        else {
            auto it = s[2].lower_bound(x); 
            
            if (it != s[2].end()) {
                tmp = *it;
                nwx = tmp - n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            else {
                auto it1 = s[1].begin(); 
                tmp = *it1;
                nwx = tmp + n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            
            if (it != s[2].begin()) {
                it--;
                tmp = *it;
                nwx = tmp - n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
            else {
                auto it1 = s[1].rbegin(); 
                tmp = *it1;
                nwx = tmp + n;
                
                res = min(abs(tmp - x), 2 * n - abs(tmp - x));
                res+= min(abs(nwx - y), 2 * n - abs(nwx - y));
                
                ans = min(ans, res + 1);
            }
        }
        
        cout << ans << endl;
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
