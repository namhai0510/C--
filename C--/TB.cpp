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

ll n, a[maxn + 2];
ll dp[maxn + 2], f[maxn + 2];
map<ll, ll> m;

void Input() {
	cin >> n;
	
	int p = 0;
	a[0] = 0;
	
	ll b[n + 2];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort(b + 1, b + 1 + n);
	
	for (int i = 1; i <= n; ++i) {
		m[b[i]]++;
		
		if (b[i] != a[p]) {
			p++;
			a[p] = b[i];
		}
	}
	n = p;
	
	// for (int i = 1; i <= n; ++i) cout << a[i] << " " << m[a[i]] << endl;
}

int main() {
    nothing
    if (fopen("TB.inp", "r")) {
        freopen("TB.inp", "r", stdin);
        freopen("TB.out", "w", stdout);
    }
    
    Input();
    
    int j = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	while (j + 1 < i && a[j + 1] < a[i] - 1) ++j;
    	
    	dp[i] = f[j] + a[i] * m[a[i]];
    	f[i] = max(f[i - 1], dp[i]);
    }
    
    cout << f[n] << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
