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

ll n, m, k;
ll l[maxn + 2], r[maxn + 2], pos = 1;
vector<char> d;

string S;

void Sub1() {
	// for (int i = 1; i <= m; ++i) cout << d[i] << " ";
	// cout << endl;
	
	for (int loop = 1; loop <= k; ++loop) {
		for (int i = 1; i <= m; ++i) {
			// cout << pos << " " << d[i] << endl;
	    	if (d[i] == 'L') pos = l[pos];
	    	else pos = r[pos];
	    }
    }
    
    cout << pos << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    
    d.pb('X');
    char P; cin >> P;
    getline(cin, S);
    d.pb(P);
    for (int i = 0; i < S.size(); ++i) {
    	if (S[i] == ' ') continue;
    	
    	d.pb(S[i]);
    }
    
    Sub1();
    
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
