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

ll m, n, res = 0;
ll a[maxn + 2], b[maxn + 2];
map<ll, ll> m1, m2;
set<ll> s;

void Input() {
	cin >> m >> n;
	
	for (int i = 1; i <= m; ++i) cin >> a[i], m1[a[i]]++, s.insert(a[i]);
	for (int j = 1; j <= n; ++j) cin >> b[j], m2[b[j]]++, s.insert(b[j]);
}

void Process() {
	for (auto val : s) {
		res += min(m1[val], m2[val]);
	}
	
	cout << res << endl;
}

int main() {
    nothing
    if (fopen("DELNUM.inp", "r")) {
        freopen("DELNUM.inp", "r", stdin);
        freopen("DELNUM.out", "w", stdout);
    }
    
    Input();
    Process();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
