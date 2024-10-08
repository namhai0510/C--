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
ll n, a[maxn + 2], S = 0;
vector<array<ll, 3>> v;


void Change(int x, int y, int z) {
	a[x] -= x * z;
	a[y] += x * z;
	v.pb({x, y, z});
}

void Input() {
	cin >> n;
	
	S = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], S += a[i];
}

void Process() {
	v.clear();
	
	if (S % n) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = 2; i <= n; ++i) {
		if (a[i] % i) Change(1, i, i - a[i] % i);
		
		Change(i, 1, a[i] / i);
	}
	
	for (int i = 2; i <= n; ++i) 
		Change(1, i, S / n);
	
	for (int i = 1; i <= n; ++i)
		assert(a[i] == S / n);
	
	assert((int)v.size() <= 3 * n);
  
	cout << v.size() << endl;
	for (auto x : v)
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
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

// https://codeforces.com/problemset/problem/1416/B
