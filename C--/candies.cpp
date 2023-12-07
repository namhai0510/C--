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

ll n;
bool Check(ll k) {
	ll sum = 0, cur = n;
	while (cur > 0) {
		ll eat = min(cur, k);
		sum += eat; cur -= eat;
		cur -= cur / 10;
	}
	
	return (sum * 2 >= n);
}

ll Bs() {
	ll l = 1, r = n, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}
int main() {
    nothing
    if (fopen("candies.inp", "r")) {
        freopen("candies.inp", "r", stdin);
        freopen("candies.out", "w", stdout);
    }
    cin >> n;
    cout << Bs() << endl;
    return 0;
}