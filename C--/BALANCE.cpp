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
ll n, a[maxn + 2];
ll res = +oo, ps[maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	ps[0] = 0;
	for (int i = 1; i <= n; ++i)
		ps[i] = ps[i - 1] + a[i];
	
	for (int i = 1; i <= n; ++i)
		res = min(res, abs(2 * ps[i] - ps[n]));
	cout << res << endl;
}

int main() {
    nothing
    if (fopen("BALANCE.inp", "r")) {
        freopen("BALANCE.inp", "r", stdin);
        freopen("BALANCE.out", "w", stdout);
    }
    
    test = 1;
    
    while (test--) {
    	Input();
    	Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
