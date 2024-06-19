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

ll n, ans[15];
string s;

int main() {
    nothing
    if (fopen("phone.inp", "r")) {
        freopen("phone.inp", "r", stdin);
        freopen("phone.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> s;
    	map<char, ll> mp;
    	
    	for (int j = 0; j < s.size(); ++j) mp[s[j]]++;
    	
    	ans[0] = mp['Z'];
	    ans[2] = mp['W'];
	    ans[4] = mp['U'];
	    ans[5] = mp['F'] - ans[4];
	    ans[6] = mp['X'];
	    ans[7] = mp['S'] - ans[6];
	    ans[8] = mp['G'];
	    ans[9] = mp['I'] - ans[5] - ans[8] - ans[6];
	    ans[1] = mp['N'] - ans[7] - 2 * ans[9];
	    ans[3] = mp['T'] - ans[2] - ans[8];
    	
    	// for (int j = 0; j <= 9; ++j) cout << ans[j] << " ";
    	for (int j = 0; j <= 9; ++j) {
    		for (int x = 1; x <= ans[j]; ++x) cout << j;
    	}
    	cout << endl;
    }
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// zero - z
// two - w
// four - u
// five - f
// six - x
// seven - s
// eight - g
// nine - i
// one - o
// three - t
