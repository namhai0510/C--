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

ll n, k;
ll a[maxn + 2], pre[maxn + 2], ans = 0;
unordered_map<ll, ll> mp;

void Case1() {
	for (int i = 1; i <= n; ++i) mp[a[i]]++;
	for (auto e : mp)
		if (e.se >= 3) ans += e.se * (e.se - 1) * (e.se - 2) / 6;
	
	cout << ans << endl;
	
	exit(0);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    if (k == 1) Case1();
    
    for (int i = 1; i <= n; ++i) {
    	if (a[i] % k == 0) pre[i] = mp[a[i] / k];
    	mp[a[i]]++;
    }
    
    mp.clear();
    
    for (int i = n; i >= 1; --i) {
        ans += pre[i] * mp[a[i] * k];
        mp[a[i]]++;
    }
 
    cout << ans << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/567/C