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

ll n, a[maxn + 2], b[maxn + 2];
ll hashL[maxn + 2], hashR[maxn + 2], POW[maxn + 2];
ll hash2[maxn + 2];

vector<ll> ans;

int getL (int l, int r) {
	return (hashL[r] - hashL[l - 1] * POW[r - l + 1] + modd * modd) % modd;
}

int getR (int l, int r) {
	return (hashR[l] - hashR[r + 1] * POW[r - l + 1] + modd * modd) % modd;
}

int get2 (int l, int r) {
	return (hash2[r] - hash2[l - 1] * POW[r - l + 1] + modd * modd) % modd;
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
    }
    
    POW[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	POW[i] = (POW[i - 1] * base) % modd;
    	hashL[i] = (hashL[i - 1] * base + a[i]) % modd;
    }
    for (int i = n; i >= 1; --i) {
    	hashR[i] = (hashR[i + 1] * base + a[i]) % modd;
    }
    
    for (int i = 1; i <= n; ++i) {
    	cin >> b[i];
    	hash2[i] = (hash2[i - 1] * base + b[i]) % modd;
    }
    
    for (int k = 1; k <= n; ++k) {
    	if (getL(k, n) == get2(1, n - k + 1)) {
    		ll length = (n - k + 1);
    		
    		if (length % 2 == 1) {
				if (getR(1, k - 1) == get2(n - k + 2, n)) ans.pb(k);
			}
			else {
				if (getL(1, k - 1) == get2(n - k + 2, n)) ans.pb (k);
			}
    	}
    }
    
    cout << ans.size() << endl;
    
    for (auto it : ans) cout << it << " ";
    
    return 0;
}
