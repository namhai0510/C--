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
const int maxn = 1e4;
const int maxa = 1e2;
const int base = 31;

int m, n;
int t[maxn + 5][maxa + 5], virus[maxa + 5];
vector<int> ans[5];

void Input() {
	cin >> m >> n;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m + 1; ++j) cin >> t[i][j];
	
	for (int j = 1; j <= m; ++j) virus[j] = 3;
}

void Process() {
	for (int i = 1; i <= n; ++i) {
		if (t[i][m + 1] == 0) 
			for (int j = 1; j <= m; ++j)
				if (t[i][j] == 1 && virus[j] == 3) virus[j] = 1;   
	}
	
	for (int i = 1; i <= n; ++i) {
		if (t[i][m + 1] == 1)
			for (int j = 1; j <= m; ++j)
				if (t[i][j] == 1 && virus[j] == 3) virus[j] = 2;
	}
	
	for (int j = 1; j <= m; ++j) ans[virus[j]].pb(j);
	
	for (int x = 1; x <= 3; ++x) {
		cout << ans[x].size() << " ";
		if (ans[x].size() != 0)
			for (auto type : ans[x]) cout << type << " ";
		cout << endl;
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
