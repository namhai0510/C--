#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, p, a[maxn + 2];
ll leng1, leng2, cnt = 0;

int main() {
    nothing
    if (fopen("saohoa.inp", "r")) {
        freopen("saohoa.inp", "r", stdin);
        freopen("saohoa.out", "w", stdout);
    }
	cin >> n >> k >> p;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	leng1 = 0; leng2 = 0;
	
	for (int i = 1; i <= n; ++i) {
		leng1 += k;
		leng2 += a[i];
		if (abs(leng1 - leng2) <= p) cnt++;
		// cout << leng1 << " " << leng2 << endl;
	}
	
	cout << cnt;
    	
    return 0;
}