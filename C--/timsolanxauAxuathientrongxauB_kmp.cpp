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

string a, b;
ll n, m;
vector<ll> v;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> a >> b;
	
	n = a.size();
	m = b.size();
	
	for (int i = 0 ; i < m; ++i) {
		if (b[i] == a[0]) {
		string s = b.substr (i, a.size());
		if (s == a) v.pb(i + 1);
		}
	}
	
	cout << v.size() << endl;
	for (int i = 0 ; i< v.size(); ++i) cout << v[i] << " ";
    return 0;
}
