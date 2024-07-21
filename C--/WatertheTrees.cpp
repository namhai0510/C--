#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll test, n, h[maxn + 2], maxval = 0;
ll l, r, mid, ans, ret;

void Input() {
	ans = +oo;
	maxval = -oo;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		maxval = max(maxval, h[i]);
	}
}

void Process(ll val) {
	l = 0, r = +oo, ret = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		
		ll cnt[3];
		cnt[0] = 0;
		cnt[1] = (mid + 1) / 2;
		cnt[2] = mid - cnt[1];
		
		for (int i = 1; i <= n; ++i) {
	        ll cur = (val - h[i]) / 2;
	        if ((val - h[i]) % 2 == 1) ++cnt[0];
	        
	        if (cnt[2] >= cur) {
	            cnt[2] -= cur;
	        } 
	        else {
	            cur -= cnt[2];
	            cnt[2] = 0;
	            cnt[0] += cur * 2;
	        }
        }
        
        if (cnt[0] <= cnt[1]) ret = mid, r = mid - 1;
    	else l = mid + 1;
	}
	
	if (ret == -1) return;
	
	ans = min(ans, ret);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	Input();
    	Process(maxval);
    	Process(maxval + 1);
    	
    	cout << ans << endl;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1661/C