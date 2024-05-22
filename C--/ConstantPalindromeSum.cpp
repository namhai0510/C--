#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll test, n, k, a[maxn + 2];
ll pref[maxn + 2], ans;
map<ll, ll> cnt;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    while (test--) {
    	cin >> n >> k;
    	
    	cnt.clear();
    	ans = +oo;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	for (int j = 0; j <= 2 * k + 1; ++j) pref[j] = 0;
    	
    	for (int i = 1; i <= n / 2; ++i) {
    		cnt[a[i] + a[n - i + 1]]++;
    	}
    	
    	for (int i = 1; i <= n / 2; ++i) {
    		pref[min(a[i], a[n - i + 1]) + 1]++;
    		pref[max(a[i], a[n - i + 1]) + k + 1]--;
    	}
    	
    	for (int j = 1; j <= 2 * k + 1; ++j) 
    		pref[j] += pref[j - 1];
    		
    	for (ll x = 2; x <= 2 * k; ++x) 
    		ans = min(ans, (pref[x] - cnt[x]) + (n / 2 - pref[x]) * 2);
    		
    	cout << ans << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/status?my=on
