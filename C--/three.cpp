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

ll n, a[maxn + 2], ans = 0;
ll mx[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    mx[n] = a[n];
    for (int i = n - 1; i >= 1; --i) mx[i] = max(mx[i + 1], a[i]);
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = i + 1; j + 1 <= n; ++j) {
    		if (a[i] < a[j] && a[j] < mx[j + 1]) ans = max(ans, a[i] + a[j] + mx[j + 1]);
    	}
    }
    cout << ans << endl;
    return 0;
}

// https://oj.vnoi.info/problem/vnoj_round_01_a
