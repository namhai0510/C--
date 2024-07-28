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

ll n, q, l, r;
vector<ll> pos[30];
string s;

void Process() {
	ll ret = 0;
	for (int i = 0; i < 26; i ++) {
        int st = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
        int en = upper_bound(pos[i].begin(), pos[i].end(), r) - pos[i].begin();
        
        if (st != pos[i].size() - 1 && st != en) 
            ret += max(pos[i][en - 1] - pos[i][st], 0LL);
    }
        
    cout << ret << endl;
    return;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> q;
    cin >> s;
    
    s = '#' + s;
    for (int i = 1; i <= n; ++i) 
    	pos[s[i] - 'a'].pb(i);
    	
    while (q --) {
        cin >> l >> r;

		Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
