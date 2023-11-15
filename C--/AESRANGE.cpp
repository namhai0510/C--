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
const int maxn = 2e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, a[maxn + 2], b[maxn + 2];
unordered_map<ll, ll> mark;
struct Data {
	ll leng, st, en;
};

bool cmp (Data A, Data B) {
	return ((A.leng < B.leng) || (A.leng == B.leng && A.st > B.st));
}

ll ans = 0;

int main() {
    nothing
    if (fopen("AESRANGE.inp", "r")) {
        freopen("AESRANGE.inp", "r", stdin);
        freopen("AESRANGE.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	b[i] = a[i] % k;
    }
    
	ll l = 1, r = 1, rr, rl;
	
	while (r <= n && l <= r) {			
		while (mark[(k - b[r]) % k] == 0 && r <= n) {
			mark[b[r]]++;
			r++;
		}
		
		if (r - l > ans) {
			ans = r - l;
			rr = r - 1;
			rl = l;
		}
		
		mark[b[l]]--;
		l++;
	}
	
	cout << ans << endl;
	for (int i = rl; i <= rr; ++i) cout << a[i] << " ";
    
    return 0;
}

// cout << l << " " << r << " " << endl;
// for (auto it : mark) cout << it.fi << " " << it.se << endl;
// cout << "---------" << endl;
