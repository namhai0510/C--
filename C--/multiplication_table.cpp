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

ll n, m, k;

bool Check(ll x) {
	ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        cnt += min(m, (x / i));
    }
    return cnt >= k;
}

ll Bs() {
	ll l = 1, r = +oo, mid, ans;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			ans = mid;
			r = mid  - 1;
		}
		else l = mid + 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> k;
    
    cout << Bs() << endl;
    
    return 0;
}