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

string x, y, res = "";
vector<string> num[2];
unordered_map<string, ll> mp;

void Get(string a, int type) {
	int n = a.size();
	a = '#' + a;
	
	for (int i = 1; i <= n; ++i) {
		string tmp = "";
		
		if (a[i] > '0' && a[i] <= '9') {
			for (int j = i; j <= n; ++j) {
				if (a[j] >= '0' && a[j] <= '9') {
					tmp += a[j];
					num[type].pb(tmp);
				}
				else break;
			}
		}
	}
	
	// remove duplicates
	sort(num[type].begin(), num[type].end());
	auto pos = unique(num[type].begin(), num[type].end());
	num[type].erase(pos, num[type].end());
}

string larger(string a, string b) {
	if (a.size() > b.size()) return a;
	if (b.size() > a.size()) return b;
	
	if (a > b) return a;
	else return b;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> x >> y;
	
	Get(x, 0);
	Get(y, 1);	
	    
	for (int i = 0; i < num[0].size(); ++i) mp[num[0][i]]++;
	
	// for (int i = 0; i <= 1; ++i) {
		// for (int x = 0; x < num[i].size(); ++x)
			// cout << num[i][x] << " ";
		// cout << endl;
	// }
	
	res = "";
	for (int i = 0; i < num[1].size(); ++i) {
		if (mp[num[1][i]]) res = larger(res, num[1][i]);
	}
	
	cout << res << endl;
	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
