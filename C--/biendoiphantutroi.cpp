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

ll t, n, a[maxn + 2];
set<ll> ans;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	
    	ans.clear();
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	a[n + 1] = +oo;
    	
    	for (int i = 1; i <= n - 1; ++i) {
    		if (a[i] == a[i + 2]
    		|| a[i] == a[i + 1])
    			ans.insert(a[i]);
    	}
    	
    	if (ans.size() == 0) {
    		cout << -1 << endl;
    		continue;
    	}
    	
    	for (auto it : ans) cout << it << " ";
    	cout << endl;
    }
    return 0;
}
