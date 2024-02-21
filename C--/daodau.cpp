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

ll n, a[maxn + 2], q, d[maxn + 2], ans[3];
ll l, r;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= q; ++i) {
    	cin >> l >> r;
    	d[l]++; d[r + 1]--;
    }
    
    ans[1] = 0; ans[2] = 0;
    
    for (int i = 1; i <= n; ++i) {
    	d[i] += d[i - 1];
    }
    
    for (int i = 1; i <= n; ++i) {
    	if (a[i] == 0) continue;
    	
    	if (d[i] % 2 == 1) a[i] *= -1;
    	
    	if (a[i] > 0) ans[1]++;
    	else ans[2]++;
    }
    
    cout << ans[1] << " " << ans[2] << endl;
    return 0;
}

// Cho mang a co n phan tu, va q truy van
// Moi truy van gom 2 so l, r, dao dau tat ca cac so trong doan tu l den r
// In ra co bao nhieu so duong, so am sau q truy van