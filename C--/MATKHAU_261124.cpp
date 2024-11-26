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
ll n, pos, c[256], ans = 0;
vector<ll> v;
string tmp = "", res ="", t = "";

int main() {
    nothing
    if (fopen("MATKHAU.inp", "r")) {
        freopen("MATKHAU.inp", "r", stdin);
        freopen("MATKHAU.out", "w", stdout);
    }
	cin >> s;
	
	n = s.size();
	
	for (int i = 1; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			v.pb(i);
			
			if (i != n / i) v.pb(n / i);
		}
	}  
	sort(v.begin(), v.end());
	
	pos = 1;
	for (int i = 0; i < v.size(); ++i) {
		while (pos <= v[i]) {
			tmp += s[pos - 1];
			pos++;
		}
		
		t = "";
		for (int j = 1; j <= n / v[i]; j++) t += tmp;
		
        if (t == s) {
            res = tmp;
            break;
        }
		
	}
	
	for (int i = 0; i < res.size(); ++i) c[s[i]]++;
	for (int i = 'a'; i <= 'z'; ++i) ans = max(ans, c[i]);
	
	cout << ans << endl;
	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
