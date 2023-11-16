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

ll n, a[maxn + 2], psum[maxn + 2];

int Bs2(ll x) {
	ll l = 0, r = n + 1, mid;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (psum[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	
	return r;
}
int main() {
    nothing
    if (fopen("Three_parts_of_the_array.inp", "r")) {
        freopen("Three_parts_of_the_array.inp", "r", stdin);
        freopen("Three_parts_of_the_array.out", "w", stdout);
    }
    cin >> n;

	psum[0] = 0; psum[n + 1] = 0;
	a[0] = 0; a[n + 1] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	
	ll sum = 0, ans = 0;
	int trace;
	for (int i = n + 1; i >= 0; --i){
		sum += a[i];
		
		int it = Bs2(sum);
		if (it >= i) break;
		
		if (sum == psum[it]) ans = sum;
	}
	
	cout << ans << endl;
	
    return 0;
}