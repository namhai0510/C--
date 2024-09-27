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

ll test;
ll a, b, c, A, B, C, ans;

void Process() {
	A = B = C = -1;
	ans = +oo;
	
	for (int aa = 1; aa <= 2 * a; ++aa) {
		for (int bb = aa; bb <= 2 * b; bb += aa) {
			for (int i = 0; i < 2; ++i) {
				int cc = bb * (c / bb) + i * bb;
				int res = abs(aa - a) + abs(bb - b) + abs(cc - c);
				
				if (ans > res) {
					ans = res;
					A = aa;
					B = bb;
					C = cc;
				}
			}
		}
	}
	
	cout << ans << endl;
	cout << A << " " << B << " " << C << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	cin >> a >> b >> c;
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1311/D
