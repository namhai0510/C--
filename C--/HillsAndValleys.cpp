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

ll test, n, a[maxn + 2], check[maxn + 2], cnt = 0, ans = 0, tmp = 0;

bool valley(int i) {
    return (i >= 2 && i <= n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

bool hill(int i) {
    return (i >= 2 && i <= n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]);
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		check[i] = 0;
    	}
    	
    	cnt = 0;
    	for (int i = 2; i <= n - 1; ++i) {
    		if (valley(i) || hill(i)) {
    			check[i] = 1;
    			cnt++;
    		}
    	}
    	
    	ans = cnt;
	    for (int i = 1; i <= n - 1; i++) {
	        tmp = a[i];
	        a[i] = a[i - 1];
	        ans = min(ans, cnt - check[i - 1] - check[i] - check[i + 1] + hill(i - 1) + valley(i - 1) + hill(i) + valley(i) + hill(i + 1) + valley(i + 1));
	        a[i] = a[i + 1];
	        ans = min(ans, cnt - check[i - 1] - check[i] - check[i + 1] + hill(i - 1) + valley(i - 1) + hill(i) + valley(i) + hill(i + 1) + valley(i + 1));
	        a[i] = tmp;
	    }
		
		cout << ans << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1467/B
