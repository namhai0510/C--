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

ll test, n, a[maxn + 2], b[maxn + 2];

void Check() {
	for (int i = n + 51; i >= 1; --i) {
		if (a[i] > b[i]) {
			cout << "YES" << endl;
			return;
		}
		else if (a[i] < b[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
	return;
}

int main() {
    nothing
    if (fopen("exchange_gems.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n + 51; ++i) a[i] = b[i] = 0;
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	for (int i = 1; i <= n; ++i) cin >> b[i];
    	
    	for (int i = 1; i <= n + 51; ++i) {
    		a[i] += a[i - 1] / 2;
    		a[i - 1] %= 2; 
    		
    		b[i] += b[i - 1] / 2;
    		b[i - 1] %= 2;
    	}
    	
    	// for (int i = 1; i <= n + 50; ++i) cout << a[i] << " ";
    	// cout << endl;
    	// for (int i = 1; i <= n + 50; ++i) cout << b[i] << " ";
    	// cout << endl;
    	
    	Check();
    	
    }
    return 0;
}

// https://oj.vnoi.info/problem/vnoicup24_r1_b
