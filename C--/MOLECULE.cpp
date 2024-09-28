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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

string s;
vector<pair<char, ll>> v;
ll n, len, cnt = 0;
char cur;

int main() {
    nothing
    if (fopen("MOLECULE.inp", "r")) {
        freopen("MOLECULE.inp", "r", stdin);
        freopen("MOLECULE.out", "w", stdout);
    }
	
	cin >> s;
	n = s.size();
	s = '#' + s;
	cur = s[0];
	len = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] != s[i - 1]) {
			v.pb({cur, len});
			
			cur = s[i];
			len = 1;
		}
		else len++;
	}
	v.pb({cur, len});
	
	// cout << v.size() << endl;
	// for (int i = 1; i < v.size(); ++i)
		// cout << v[i].fi << " " << v[i].se << endl;
		
	cnt = (v.size() - 2) / 2;
	if (v[1].fi == v[v.size() - 1].fi) cnt--;
	
	cout << cnt << endl;
	    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
