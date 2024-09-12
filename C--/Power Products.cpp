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

ll n, k, a[maxn + 2], ans = 0;
map<vector<pair<ll, ll>>, ll> freq;
vector<pair<ll, ll>> PF[maxn + 2];

void factor(ll x, int pos) {
	map<ll, ll> F;
	
	for (int i = 2; i * i <= x; ++i)
		while (x % i == 0) {
			F[i]++;
			x /= i;
		}
		
	if (x > 1) F[x]++;
	
	for (auto f : F)
		if (f.se % k > 0) 
			PF[pos].pb({f.fi, f.se % k});
	
	freq[PF[pos]]++;
}

void check_inverse(int pos) {
	int sz = PF[pos].size();
	vector<pair<ll, ll>> v;
	
	for (int i = 0; i < sz; ++i) 
		v.pb({PF[pos][i].fi, k - PF[pos][i].se});
		
	if (PF[pos] == v) 
		ans += freq[PF[pos]] - 1;
	else 
		ans += freq[v];
	
	return;
}
void Input() {
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		factor(a[i], i);
	}
}

void Process() {
	for (int i = 1; i <= n; ++i) check_inverse(i);
	
	cout << ans / 2 << endl;
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

// https://codeforces.com/problemset/problem/1225/D
