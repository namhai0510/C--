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

int n, a[maxn + 2];
int dp[5][maxn + 2], t[5][maxn + 2], f[maxn + 2], res, pos;

int Get(int id, int x) {
	int ret = 0;
	
	if (id % 2 == 1) {
		for (; x > 0; x -= (x & -x)) ret = max(ret, t[id][x]);
	}
	else {
		for (; x <= f[0]; x += (x & -x)) ret = max(ret, t[id][x]);
	}
	
	return ret;
}

void Update(int id, int x, int v) {
	if (id % 2 == 0) {
		for (; x > 0; x -= (x & -x)) t[id][x] = max(v, t[id][x]);
	}
	else {
		for (; x <= f[0]; x += (x & -x)) t[id][x] = max(v, t[id][x]);
	}
}

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[++f[0]] = a[i];
	}
	f[++f[0]] = 0;
	
	sort(f + 1, f + f[0] + 1);
	f[0] = unique(f + 1, f + f[0] + 1) - f - 1;
}

void Process() {
	for (int id = 1; id <= 4; ++id) {
		for (int i = 1; i <= n; ++i) {
			if (id % 2) pos = upper_bound(f + 1, f + f[0] + 1, a[i] - 1) - f - 1;
			else pos = upper_bound(f + 1, f + f[0] + 1, a[i]) - f;
			
			dp[id][i] = Get(id, pos) + 1;
			
			if (id > 1 && dp[id][i] < id + 1) dp[id][i] = 0;
			
			pos = lower_bound(f + 1, f + f[0] + 1, a[i]) - f;
			if (id == 1) Update(id, pos, dp[id][i]);
			else if (id == 2) {
				Update(id, pos, dp[id][i]);
				if (dp[id - 1][i] > 1) Update(id, pos, dp[id - 1][i]);
			}
			else {
				Update(id, pos, dp[id][i]);
				Update(id, pos, dp[id - 1][i]);
			}
		}
	}
	
	res = 0;
	for (int i = 1; i <= n; ++i)
		res = max(res, dp[4][i]);
		
	cout << res << endl;
}

int main() {
    nothing
    if (fopen("mchar.inp", "r")) {
        freopen("mchar.inp", "r", stdin);
        freopen("mchar.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
