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
const int maxa = 3e3 + 5;
const int base = 31;

const int dx[4] = {0, 0, 1, 1};
const int dy[4] = {0, 1, 0, 1};

ll n, a[maxa + 2][maxa + 2], b[maxa + 2][maxa + 2];
bool exist = 0;

bool Inside(int x, int y) {
	return ((1 <= x && x <= n) && (1 <= y && y <= n));
}

bool Check(int x1, int y1, int x2, int y2) {
	if (!Inside(x1, y1)) return 1;
    if ((x1 == n) || (y1 == n)) return 1;
    int p, q, val = a[x1][y1];
    for (int i = 0; i < 4; ++i) {
        p = x1 + dx[i];
        q = y1 + dy[i];
        if ((Inside(p, q)) && (b[p][q])) val--;
    }
    
    return (x2 <= val) && (val <= y2);
}


void BruteForce(int p, int q, int x, int y) {
    if (exist) return;
    
    if (p > n) {
        exist = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cout << b[i][j] << " ";
            cout << endl;
        }
        return;
    }
    
    for (int k = 0; k <= 1; ++k) {
        b[x][y] = k;
        if (!Check(x - 1, y - 1, 0, 0)) continue;
        if (!Check(x - 1, y, 0, 1)) continue;
        if (!Check(x, y - 1, 0, 2)) continue;
        
        int x2 = x + 1, y2 = y - 1;
        if (Inside(x2, y2)) BruteForce(p, q, x2, y2);
        else {
            if (q < n) BruteForce(p, q + 1, p, q + 1);
            else BruteForce(p + 1, q, p + 1, q);
        }
    }
    
    b[x][y] = 0;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i < n; ++i) 
    	for (int j = 1; j < n; ++j) cin >> a[i][j];
    	
    BruteForce(1, 1, 1, 1);
    
    if (!exist) cout << "No solution" << endl;  
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/aladdin