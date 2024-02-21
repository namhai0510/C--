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
ll ans = 0, s = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    for (int i = n; i >= 1; --i) {
    	if (a[i] - s <= 0) break;
    	
    	ans += a[i] - s;
    	s++;
    }
    
    cout << ans << endl;
    return 0;
}
// Cho mang a co n phan tu. Moi luot co the chon 1 so a[i] de cong vao ket qua, va tat 
// ca cac so con lai se giam di 1 don vi. In ra man hinh ket qua lon nhat co the
// (Ket thuc khi mang khong con phan tu hoac toan 0)