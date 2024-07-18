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

ll n, mx;
string s, ans = "";
ll a[maxn + 2], dp[maxn + 2], de[maxn + 2], b[maxn + 2], trace[maxn + 2];

void preprocess() {
	s = "@" + s;
	for (int i = 1; i <= n; ++i) a[i] = +oo;
	mx = 1;
	b[1] = 1;
}

string get(int best) {
	vector<pair<char, int>> v;
    while (best) {
        v.pb({s[best], best});
        best = trace[best];
    }
    
	reverse(v.begin(), v.end());
	
	string ss = "";
	
	int j = 0;
	while (j < v[0].se - 1){
		ss += 'a';
		++j;
	}
	
	for (int i = 0; i < mx - 1; ++i) {
		pair<ll, ll> mxl = v[i + 1];
		
		while (j < mxl.se - 1) {
			ss += char(v[i].fi);
			++j;
		}
	}
	
	while (j < n) {
		ss += char(v[mx - 1].fi);
		j++;
	}
	
	return ss;
}

void process() {
	for (int i = 1; i <= n; ++i) {
		int pos = upper_bound(a + 1, a + 1 + n, s[i] - 'a') - a;
		dp[i] = pos;
		trace[i] = b[pos - 1];
		a[pos] = s[i] - 'a';
		if (pos > mx){
            mx = pos;
            b[pos] = i;
        }
        else if (s[b[pos]] > s[i])
        	b[pos] = i;
        }
        	
	ans = "";
	for(int i = 1 ; i <= n ; ++i) ans += 'z';
    for (int i = 1 ; i <= n ; ++i)
        if (dp[i] == mx) ans = min(ans, get(i));
        
	cout << ans;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    cin >> s;
    
    preprocess();
    process();
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
