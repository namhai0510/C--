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

ll t, n;
char c, a[2 * maxn + 2];
vector<int> lo;

int Bs2 (int x) {
    int l, r, mid;
    l = 0; r = lo.size() - 1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (lo[mid] >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    return l;
}

int main() {
    nothing
    if (fopen("traffic_light.inp", "r")) {
        freopen("traffic_light.inp", "r", stdin);
        freopen("traffic_light.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	lo.clear();
    	cin >> n >> c;
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    		a[n + i] = a[i];
    		if (a[i] == 'g') {
    			lo.pb(i);
    			lo.pb(i + n);
    		}
    	}
    	sort(lo.begin(), lo.end());
    	
    	int j = 0, ans = 0;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] == c) {
    			while (lo[j] < i) j++;
    			ans = max(ans, lo[j] - i);
    		}
    	}
    	
    	cout << ans << endl;
    }
    
    return 0;
}