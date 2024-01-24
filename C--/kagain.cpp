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

ll t, n, a[maxn + 2], l[maxn + 2], r[maxn + 2];
ll ans, st, en;

deque<ll> d;

int main() {
    nothing
    if (fopen("kagain.inp", "r")) {
        freopen("kagain.inp", "r", stdin);
        freopen("kagain.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
	    	cin >> a[i];
	    } 
	    
	    d.clear();
    	
    	for (int i = 1; i <= n; ++i) {
    		while (d.size() && a[d.back()] >= a[i]) d.pop_back();
			
			if (d.size() == 0) l[i] = 1;
			else l[i] = d.back() + 1;
			
			d.push_back(i);
    	}
    	
    	d.clear();
    	
    	for (int i = n; i >= 1; --i) {
    		while (d.size() && a[d.front()] >= a[i]) d.pop_front();
			
			if (d.size() == 0) r[i] = n;
			else r[i] = d.front() - 1;
			
			d.push_front(i);
    	}
    	
    	ans = 0; st = +oo;
    	for (int i = 1; i <= n; ++i) {
    		if (ans == a[i] * (r[i] - l[i] + 1)) {
    			if (l[i] < st) {
    				st = l[i];
    				en = r[i];
    			}
    			
    			// cout << i << " " << l[i] << " " << r[i] << " " << a[i] << endl;
    		}
    		else if (ans < a[i] * (r[i] - l[i] + 1)) {
    			ans = a[i] * (r[i] - l[i] + 1);
    			st = l[i];
    			en = r[i];
    			
    			// cout << i << " " << l[i] << " " << r[i] << " " << a[i] << endl;
    		}
    	}
    	
    	cout << ans << " " << st << " " << en << endl;
    }
	     
    return 0;
}

// https://oj.vnoi.info/problem/kagain
