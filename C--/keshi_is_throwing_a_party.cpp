#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e17 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n;
struct Data {
	ll a, b, d;
} x[maxn + 2];

ll Check(ll val) {
	// muon moi duoc val nguoi
	ll cnt = 0;
	for(int i = 1; i <= n; ++i){
		// gia su muon moi x nguoi
		// neu co i nguoi ngheo hon nguoi v, thi co x - i - 1 nguoi se giau hon 
		// nguoi v
		// -> i <= b[v], x - i - 1 <= a[v]
		// -> i <= b[v], x - 1 - a[v] <= i
		if (val - 1 - x[i].a <= cnt && cnt <= x[i].b) cnt++;
	}
	return cnt >= val;
}

ll Bs() {
	ll l = 0, r = n + 1, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	return ans;
}
int main() {
    nothing
    if (fopen("keshi_is_throwing_a_party.inp", "r")) {
        freopen("keshi_is_throwing_a_party.inp", "r", stdin);
        freopen("keshi_is_throwing_a_party.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		cin >> x[i].a >> x[i].b;
    		x[i].d = i;
    	}
    	
    	cout << Bs() << endl;
    }
    return 0;
}