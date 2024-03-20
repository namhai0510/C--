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

ll n, a[maxn + 2], val[maxn + 2], vis[maxn + 2];
char ans[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	val[a[i]] = i;
    }
    
    for (int i = n; i >= 1; --i) {
    	ll x = val[i];
    	
    	for (int j = x % i; j <= n; j += i) {
    		if (a[j] > i && vis[j] == 0) {
    			vis[x] = 1;
    			break;
    		}
    	}
    	
    	if (vis[x] == 1) ans[x] = 'A';
    	else ans[x] = 'B';
    }
    
    for (int i = 1; i <= n; ++i) {
    	cout << ans[i];
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1033/C