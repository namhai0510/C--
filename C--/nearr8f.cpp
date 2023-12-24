#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, pos = 1, res;
ll a[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    // (i - 1) * n + j
    
	for (int j = 1; j <= (n + 1) / 2; ++j) {
		if (j % 2 == 1) {
			for (int i = m; i >= 1; --i) {
				a[(i - 1) * n + j] = pos;
				pos++;
			}
			for (int i = 1; i <= m; ++i) {
				if ((i - 1) * n + (n - j + 1) == (i - 1) * n + j) continue;
				a[(i - 1) * n + (n - j + 1)] = pos;
				pos++;
			}
		}
		else {
			for (int i = m; i >= 1; --i) {
				a[(i - 1) * n + (n - j + 1)] = pos;
				pos++;
			}
			for (int i = 1; i <= m; ++i) {
				if ((i - 1) * n  + j == (i - 1) * n + (n - j + 1)) continue;
				a[(i - 1) * n + j] = pos;
				pos++;
			}
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) cout << a[(i - 1) * n + j] << " ";
		cout << endl;
	}
    return 0;
}
