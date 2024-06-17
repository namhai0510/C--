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
   
ll n, h, a[maxn + 2], x[maxn + 2];
ll ans, cnt;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> h;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	 
    	if (i % 2) x[1]++, x[a[i] + 1]--;
    	else x[h - a[i] + 1]++;
    }
    
    ans = n + 1, cnt = 0;
    
    for (int i = 1; i <= h; ++i) {
        x[i] += x[i - 1];
        if (x[i] < ans) ans = x[i], cnt = 1;
        else cnt += (x[i] == ans);
    }
    cout << ans << " " << cnt << endl;
    return 0;
}

// https://oj.vnoi.info/problem/c11cave
