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

ll t, n, a[maxn + 2], d[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 1; i <= n; ++i) {
    		cin >> d[i];
    	}
    	a[0] = a[n + 1] = 0;
    	d[0] = d[n + 1] = +oo;
    	set<ll> alive, arr;
    	for (int i = 0; i <= n + 1; ++i) {
    		arr.insert(i);
    		alive.insert(i);
    	}
    	
    	for (int round = 1; round <= n; ++round) {
    		set<ll> del, cur;
    		
    		for (auto i : alive) {
    			auto it = arr.find(i);
    			if (it == arr.end()) continue;
    			
    			int prv = *prev(it), nxt = *next(it);
    			
    			if (a[prv] + a[nxt] > d[i]) {
    				del.insert(i);
    				cur.insert(prv);
    				cur.insert(nxt);
    			}
    		}
    		
    		cout << del.size() << " ";
    		
    		for (auto i : del) arr.erase(i);
    		alive = cur;
    	}
    	cout << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1922/D