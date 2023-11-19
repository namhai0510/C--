#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, a[maxn + 2], b[maxn + 2];

int Bs3 (ll x) {
	int l = 1, r = n, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (a[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	
	return r;
}
int main() {
    nothing
    if (fopen("queries_about_less_or_equal_elemets.inp", "r")) {
        freopen("queries_about_less_or_equal_elemets.inp", "r", stdin);
        freopen("queries_about_less_or_equal_elemets.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= m; ++i) {
    	cout << Bs3(b[i]) << " ";
    }
    
    return 0;
}