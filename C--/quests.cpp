#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e13 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, c, d, a[maxn + 2], sum;

bool Check(ll val) {
	val++;
	ll res = 0, cnt = 0;
	for (int i = 1; i <= min(n, val); ++i) {
		cnt = (d - i) / val + 1;		
		res += cnt * a[i];
	}
	
	return res >= c;
}

ll Bs() {
	ll l = 0, r = d, mid, ans;
	
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

bool cmp(ll a, ll b) {
	return (a > b);
}

int main() {
    nothing
    if (fopen("quests.inp", "r")) {
        freopen("quests.inp", "r", stdin);
        freopen("quests.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> c >> d;
    	sum = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	sort(a + 1, a + 1 + n, cmp);
    	
    	for (int i = 1; i <= min(n, d); ++i) sum += a[i];
    	
    	if (sum >= c) cout << "Infinity" << endl;
    	else if (a[1] * d < c) cout << "Impossible" << endl;
    	else cout << Bs() << endl;
    }
    return 0;
}