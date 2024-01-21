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

ll t, n, k, a[maxn + 2], mra[maxn + 2];

deque<ll> d;
int main() {
    nothing
    if (fopen("mink.inp", "r")) {
        freopen("mink.inp", "r", stdin);
        freopen("mink.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> k;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	while (d.size()) d.pop_front();
    	
    	for (int i = 1; i <= n; ++i) {
    		while (d.size() && a[d.back()] >= a[i]) d.pop_back();
    		
    		d.push_back(i);
    		
    		if (d.front() + k <= i) d.pop_front();
    		
    		if (i >= k) mra[i] = a[d.front()];
    	}
    	
    	for (int i = k; i <= n; ++i) {
    		cout << mra[i] << " ";
    	}
    	cout << endl;
    }
    
    return 0;
}

// https://oj.vnoi.info/problem/mink