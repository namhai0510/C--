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

ll test, n, k, S = 0, a[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n >> k;
    	
    	S = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		S += a[i];
    		a[i] += i;
    	}
    	sort(a + 1, a + 1 + n, greater<ll>());
    	
    	for (int i = 1; i <= k; ++i) {
    		S -= a[i];
    		S += n - i + 1;
    	}
    	
    	cout << S << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1684/D
