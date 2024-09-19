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

ll n, d, m;
ll l1, l2, ans = 0;
ll a[maxn + 2], b[maxn + 2], c[maxn + 2];


void Input() {
	cin >> n >> d >> m;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	for (int i = 1; i <= n; ++i) {
		if (a[i] > m) b[++l1] = a[i];
		else c[++l2] = a[i];
	}
	
	if (l1 == 0) {
		for (int i = 1; i <= n; ++i) c[i] += c[i - 1];
		
		cout << c[n] << endl;
		return;
	}
	
	sort(b + 1, b + 1 + l1, greater<ll>());
	sort(c + 1, c + 1 + l2, greater<ll>());
	
	for (int i = 1; i <= l1; ++i) b[i] += b[i - 1];
	for (int i = 1; i <= l2; ++i) c[i] += c[i - 1];
	
	for (int i = l2 + 1; i <= n; ++i) c[i] = c[l2];

	for (int i = (l1 + d) / (d + 1); i <= l1; ++i)
		if (1LL * (i - 1) * (d + 1) + 1 <= n)
			ans = max(ans, b[i] + c[n - 1LL * (i - 1) * (d + 1) - 1]);
			
	cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	Input();
	Process();
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1394/A