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

ll test, n, a[maxn + 2];
ll ans = 0;

ll dist(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (i + 2 <= j) {
				bool ok = true;
				for (int x = i; x < j; ++x) 
					for (int y = x + 1; y < j; ++y) {
						pair<ll, ll> X = {a[x], x};
						pair<ll, ll> Y = {a[y], y};
						pair<ll, ll> Z = {a[j], j};
						if (dist(X, Z) == dist(X, Y) + dist(Y, Z)) ok = false;
					}
				
				if (!ok) break;
			}
			ans++;
		}
	}
	
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

// https://codeforces.com/problemset/problem/1550/C
