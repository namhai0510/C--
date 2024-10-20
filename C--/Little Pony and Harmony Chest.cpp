#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const int oo = 1e5;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 1e2;
const int base = 31;

int mark[64];
vector<int> P;
int n, a[maxa + 2], ans, pos;
int dp[maxa + 2][(1 << 17) + 2], par[maxa + 2][(1 << 17) + 2];
int g[64][20], d[64];

void Print(int num, int index) {
	if (num == 1) {
		cout << par[num][index];
		return;
	}
	
	Print(num - 1, index ^ d[par[num][index]]);
	cout << " " << par[num][index];
}

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	for (int i = 2; i * i <= 60; ++i)
		for (int j = i; j * i <= 60; ++j)
			mark[i * j] = 1;
			
	for (int i = 2; i <= 60; ++i)
		if (!mark[i]) P.pb(i);
	
	for (int i = 1; i <= 60; ++i) {
		for (int j = 0; j < 17; ++j) 
			if (i % P[j] == 0) g[i][j] = 1;
			
		int cur = 0;
		for (int j = 16; j >= 0; --j)  {
			cur = (cur << 1);
			cur += (g[i][j] ? 1 : 0);
		}
		
		d[i] = cur;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= (1 << 17); ++j) 
			dp[i][j] = +oo; 
	
	for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 60; ++j) {
            int X = ((1 << 17) - 1) ^ (d[j]);
            
            for (int k = X; ; k = (k - 1) & X) {
                int cur = dp[i - 1][k] + abs(a[i] - j);
                
                if (cur < dp[i][k | d[j]]) {
                    dp[i][k | d[j]] = cur;
                    par[i][k | d[j]] = j;
                }
                
                if (k == 0) break;
            }
        }
    }
    
	ans = +oo;
	pos = -1;
	
	
	for (int j = 0; j <= (1 << 17); ++j) {
		if (ans > dp[n][j]) {
			ans = dp[n][j];
			pos = j;
		}
	}
	
	Print(n, pos);
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

// https://codeforces.com/problemset/problem/453/B
