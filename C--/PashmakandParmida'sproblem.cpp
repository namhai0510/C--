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
const int base = 31;

ll n, a[maxn + 2], b[maxn + 2], tmp[maxn + 2];
ll L[maxn + 2], R[maxn + 2], cnt[maxn + 2], ans = 0;

ll Get(ll l, ll r) {
	if (r <= l + 1) return 0;
	
	ll mid = (l + r) / 2;
	ll ret = Get(l, mid) + Get(mid, r);
	
	ll x = l, y = mid;
	
	while (x != mid || y != r) {
		ll val[2] = {(x < mid ? L[x] : +oo), (y < r ? R[y] : +oo)};
        if (val[0] <= val[1]) {
            ++x;
            ret += y - mid;
        }
        else ++y;
	}
	
	merge(L + l, L + mid, L + mid, L + r, tmp);
    for (int i = 0; i < r - l; ++i) L[i + l] = tmp[i];
    merge(R + l, R + mid, R + mid, R + r, tmp);
    for (int i = 0; i < r - l; ++i) R[i + l] = tmp[i];
    
    return ret;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
    	cnt[a[i]]++;
    	L[i] = cnt[a[i]];
    }
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i >= 1; --i) {
    	cnt[a[i]]++;
    	R[i] = cnt[a[i]];
    }
    
    ans = Get(1, n + 1);
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/459/D
