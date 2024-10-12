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
ll n, x, e;
ll a[maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	cin >> x;
}

void Process() {
	e = n;
	for (int i = 1; i <= n; ++i)
		a[i] -= x;
	
	for (int i = 2; i <= n; ++i) 
		if (a[i - 1] + a[i] < 0 || a[i - 2] + a[i - 1] + a[i] < 0) {
			e--;
			a[i] = +oo;
		}
		
	cout << e << endl;
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

// https://codeforces.com/problemset/problem/1616/D
