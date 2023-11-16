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

ll n, a[maxn + 2];

int main() {
    nothing
    if (fopen("Three_parts_of_the_array.inp", "r")) {
        freopen("Three_parts_of_the_array.inp", "r", stdin);
        freopen("Three_parts_of_the_array.out", "w", stdout);
    }
    cin >> n;

	a[0] = 0; a[n + 1] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	ll sumL = a[0], sumR = a[n + 1], ans = 0;
	int l = 0, r = n + 1;
	
	while (l < r) {
		if (sumL == sumR) {
			ans = sumL;
			l++; r--;
			sumL += a[l]; sumR += a[r];
		}
		else if (sumL > sumR) {
			r--;
			sumR += a[r];
		}
		else if (sumL < sumR) {
			l++;
			sumL += a[l];
		}
	}
	cout << ans;
	
    return 0;
}