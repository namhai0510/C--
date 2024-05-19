#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll n, a[maxn + 2], f[1005][1005];
ll ans = 300001;

void back(long long pos, long long x, long long tick) {
	long long i, temp, tp;
	
	if (pos > n) {
		ans= min(ans, x);
		return;
	}
	for (i=(tick==0); i<=1; i++) {
		temp= tick + i*(a[pos] > 100) - (i==0);
		tp= x + i*a[pos];
		if (tp < f[pos][temp]) {
			f[pos][temp]= tp;
			back(pos+1, tp, temp);
		}
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j]= 300001;

	back(1, 0, 0);
	cout << ans;
    return 0;
}

// https://oj.vnoi.info/problem/c11km
