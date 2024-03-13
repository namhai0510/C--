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

ll n, a[maxn + 2];
ll d1[maxn + 2], d2[maxn + 2], ans = 0;

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
    
    d2[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
    	if (a[i] < a[i + 1]) d2[i] = d2[i + 1] + 1;
    	else d2[i] = 1;
    	
    	ans = max(ans, d2[i]);
    }
    
    d1[1] = 1;
    for (int i = 2; i <= n; ++i) {
    	if (a[i] > a[i - 1]) d1[i] = d1[i - 1] + 1;
    	else d1[i] = 1;
    }
    
    for (int i = 2; i <= n - 1; ++i) {
    	if (a[i - 1] < a[i + 1]) ans = max(ans, d1[i - 1] + d2[i + 1]);
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1272/D