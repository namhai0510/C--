#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
int n;
ll a[maxn];

set<ll> s, factor, info;
map<ll, bool> ch;
map<ll, int> cnt;

signed main() {
    nothing
    Eratos();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 1) s.insert(a[i]);
    }
    
    while (1) {
        ch.clear(); info.clear();
        
        for (auto val = s.begin(); val != s.end(); val++) {
            auto val2 = next(val);
            
            while (val2 != s.end()) {
				ll x = __gcd(*val, *val2);
				if (x != 1) {
					info.insert(x);
					ch[*val] = 1; ch[*val2] = 1;
					info.insert(*val / x);
					info.insert(*val2 / x);
					break;
				}
				++val2;
			}
			
			if (ch[*val] == 0) {
				factor.insert(*val);
			}
        }
        
        info.erase(1);
        if (info.size() == 0) break;
        s = info;
    }
    
    for (int i = 1; i <= n; i++) {
        for (ll j : factor) if (a[i] % j == 0) cnt[j]++;
	}
	
	int ans = 0;
	for (auto [x, y] : cnt) {
		ans = max(ans, y);
	}
	
	cout << ans;
}

// Cho số nguyên dương . Hãy chọn nhiều số nhất để ước chung lớn nhất của các số
// được chọn lớn hơn 1.
