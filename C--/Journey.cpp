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

ll test, n;
string s;
ll f[2][maxn + 2][2];

void Input() {
	cin >> n >> s;
	
	s = '#' + s;
	for (int i = 0; i <= n; ++i) f[1][i][0] = f[1][i][1] = f[0][i][0] = f[0][i][1] = i;
}

void Process() {
	for (int i = n - 1; i >= 0; --i) {
		if (s[i + 1] == 'L') f[1][i][0] = f[1][i + 1][1];
		else f[1][i][1] = f[1][i + 1][0];
	}
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'L') f[0][i][0] = f[0][i - 1][1];
		else f[0][i][1] = f[0][i - 1][0];
	}
	
	for (int i = 0; i <= n; ++i) {
		int l = i, r = i;
		
		if (i != 0 && s[i] == 'L') l = f[0][i][0];
		if (i != n && s[i + 1] == 'R') r = f[1][i][1];
		
		cout << r - l + 1 <<  " "; 
	}
	
	cout << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1476/D
