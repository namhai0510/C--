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
const int maxn = 2e5;
const int maxa = 2e3;
const int base = 31;

int test;
ll n, a[maxn + 2], b[maxn + 2], LIM, res;;
int f[650][maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
}

void Process() {
	res = 0;
	LIM = sqrt(2 * n);
	
	for (int i = 1; i <= n; ++i)
		if (a[i] <= LIM) f[a[i]][b[i]]++;
		
	for (int i = 1; i <= n; ++i) 
		if (a[i] <= LIM)
			if (a[i] * a[i] - b[i] > 0 && a[i] * a[i] - b[i] <= n)
				res += f[a[i]][a[i] * a[i] - b[i]];	
	
	for (int i = 2; i <= LIM; i += 2)
		res -= f[i][i * i / 2];
	
	res /= 2;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1LL; j <= LIM && j < a[i] && j * a[i] <= 2 * n; ++j) {
			if (j * a[i] - b[i] > 0 && j * a[i] - b[i] <= n)
				res += f[j][j * a[i] - b[i]];
		}
	
	for (int i = 1; i <= n; ++i)
		if (a[i] <= LIM) f[a[i]][b[i]] = 0;
	cout << res << endl;	
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

// https://codeforces.com/problemset/problem/1830/B
