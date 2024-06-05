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

ull n, ans = 0;
ull factor[15000000 + 2], freq[15000000 + 2], g = 1;

ull GCD(ull a, ull b) {
    if (a == 0) return b;
    return GCD(b % a, a);
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    for (int i = 2; i <= maxn; ++i) {
    	if (factor[i] != 0) continue;
    	
    	for (int j = i; j <= maxn; j += i) 
    		if (!factor[j]) factor[j] = i;
    }
    
    cin >> n;
    ull a[n + 2];
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	if (i == 1) g = a[i];
    	else g = GCD(g, a[i]);
    }
    
    // cout << g << endl;
    
    for (int i = 1; i <= n; ++i) {
        a[i] /= g;
        
        while (a[i] > 1) {
            ll tmp = factor[a[i]];
            freq[tmp]++;
            ans = max(ans, freq[tmp]);
            
            while (a[i] > 1 && a[i] % tmp == 0) a[i] /= tmp;
        }
    }
    
    // cout << ans << endl;
    
    if (ans) cout << n - ans << endl;
    else cout << -1 << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1034/A?csrf_token=62e3c3ca181a447b49aca2357538064d
