#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

string s;
ll n, ps[maxn + 2];
map<ll, ll> mp;

bool Valid(ll mid) {
	mp.clear();
	
	for (int i = 1; i <= n - mid + 1; ++i) {
		mp[ps[i + mid - 1] - ps[i - 1]]++;
		
		if (mp[ps[i + mid - 1] - ps[i - 1]] >= 2) return 1;
	}
	
	return 0;
}

int main() {
    nothing
    if (fopen("sstring1.inp", "r")) {
        freopen("sstring1.inp", "r", stdin);
        freopen("sstring1.out", "w", stdout);
    }
    cin >> s;
    
    n = s.size();
    s = '#' + s;
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	ps[i] = ps[i - 1] + (s[i] == '1');
    }
    
    ll l = 1, r = n - 1, mid;
    
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	if (Valid(mid)) l = mid + 1;
    	else r = mid - 1;
    }
    
    cout << r << endl;
    return 0;
}
