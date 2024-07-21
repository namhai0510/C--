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

ll test;
ll n, a[maxn + 2];
ll pf[maxn + 2], sf[maxn + 2], ans = 0;

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		pf[i] = a[i] + i;
		sf[i] = a[i] - i;
	}
	
	for (int i = 2; i <= n; ++i) 
		pf[i] = max(pf[i], pf[i - 1]);
	for (int i = n - 1; i >= 1; --i) 
		sf[i] = max(sf[i], sf[i + 1]);
		
	for (int i = 2; i <= n - 1; ++i) ans = max(ans, a[i] + pf[i - 1] + sf[i + 1]);
	
	cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1826/D
