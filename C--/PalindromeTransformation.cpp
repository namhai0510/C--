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

ll n, m, p, ans = 0, l, r, ret;
vector<ll> pos;
string s;

void Init() {
	s = '#' + s;
	
	bool change = 0;
    for (int i = 1; i * 2 <= n; ++i) {
    	if (s[i] != s[n - i + 1]) {
    		ans += min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
    		change = 1;
    		pos.pb(i);
    	}
    }
    
    if (!change) {
    	cout << 0 << endl;
    	exit(0);
    }
    
    m = pos.size();
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> p;
    cin >> s;
    
    Init();
    
    l = pos[0], r = pos[m - 1];
    
    ret = 0;
    if (p * 2 > n) p = n - p + 1;
    
    if (p <= l) ret = r - p;
	else if (p >= r) ret = p - l;
	else ret = min(abs(p - l) + r - l , abs(p - r) + r - l );
    
    cout << ans + ret << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/486/C
