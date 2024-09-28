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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll test;
ll n, k, c[maxn + 2], a[maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> c[i];
	
	cin >> k;	
}

void Process() {
	c[0] = 0;
	a[0] = +oo;
	
	for (int i = n - 1; i >= 1; --i) c[i] = min(c[i], c[i + 1]);
	
	for (int i = 1; i <= n; ++i) {
		if (c[i] == c[i - 1]) a[i] = a[i - 1];
		else a[i] = min(k / (c[i] - c[i - 1]), a[i - 1]);
		
		k -= (c[i] - c[i - 1]) * a[i];
	}
	
	for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	cout << endl;
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

// https://codeforces.com/problemset/problem/1870/D