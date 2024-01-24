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

ll n, a[maxn + 2], l[maxn + 2], r[maxn + 2], ans, res;

deque<ll> d;
int main() {
    nothing
    if (fopen("kplank.inp", "r")) {
        freopen("kplank.inp", "r", stdin);
        freopen("kplank.out", "w", stdout);
    }
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
	
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (r[i] - l[i] + 1 >= a[i]) {
			if (ans < a[i] * a[i]) {
				ans = a[i] * a[i];
				res = a[i]; 
			}
		}
	}
	
	cout << res << endl;
    return 0;
}

// https://oj.vnoi.info/problem/kplank
