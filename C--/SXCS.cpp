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
vector<ll> v;
ll c0 = 0;

int main() {
    nothing
    if (fopen("SXCS.inp", "r")) {
        freopen("SXCS.inp", "r", stdin);
        freopen("SXCS.out", "w", stdout);
    }
    cin >> s;
    
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] == '0') {
    		c0++;
    		continue;
    	}
    	
    	v.pb(s[i] - '0');
    }
    sort(v.begin(), v.end());
    
    cout << v[0];
    for (int i = 1; i <= c0; ++i) cout << 0;
    for (int i = 1; i < v.size(); ++i) cout << v[i];
    
    cout << endl;
    
    reverse(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); ++i) cout << v[i];
    for (int i = 1; i <= c0; ++i) cout << 0;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
