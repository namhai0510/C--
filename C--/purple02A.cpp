#include<bits/stdc++.h>
using namespace std;

#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n";
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const ll maxn = 1e6 + 2;
const ll maxa = 2e3 + 2;

ll x[3], y[3], a[3];

int main() {
	nothing
	if (fopen("ss.inp", "r")) {
		freopen("ss.inp", "r", stdin);
		freopen("ss.out", "w", stdout);
	}
	cin >> x[1] >> y[1] >> a[1];
	cin >> x[2] >> y[2] >> a[2];
	
	if (x[1] == x[2] && y[1] == y[2] && a[1] == a[2]) {
		cout << 1 << endl;
	}
	else if ((x[2] <= x[1] && y[2] <= y[1] && x[1] + a[1] <= x[2] + a[2] && y[1] + a[1] <= y[2] + a[2])
			|| (x[1] <= x[2] && y[1] <= y[2] && x[2] + a[2] <= x[1] + a[1] && y[2] + a[2] <= y[1] + a[1])) {
		cout << 2 << endl;
	}
	else if (x[1] + a[1] <= x[2] || x[2] + a[2] <= x[1] || y[1] + a[1] <= y[2] || y[2] + a[2] <= y[1]) {
        cout << 4 << endl;
    }
	else cout << 3;
	return 0;
}

