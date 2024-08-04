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

ll test, n, c[2 * maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> c[i];
}


void Process() {
	ll cnt = 0, st, en;
	for (int i = 1; i <= n; ++i) 
		if (c[i] == 1) cnt++;
		
	if (cnt != 1) {
		cout << "NO" << endl;
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (c[i] == 1) {
			st = i;
			en = i - 1;
			break;
		}
	}
	
	c[n + 1] = c[1];
	c[0] = c[n];
	for (int i = st; i <= n; ++i) 
		if (c[i] - c[i - 1] > 1) {
			cout << "NO" << endl;
			return;
		}
	for (int i = 1; i <= en; ++i)
		if (c[i] - c[i - 1] > 1) {
			cout << "NO" << endl;
			return;
		}
		
	cout << "YES" << endl;
	return;
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

// https://codeforces.com/problemset/problem/1658/C
