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

ll n, x, ans = 0;

int main() {
	nothing
	if (fopen("ss.inp", "r")) {
		freopen("ss.inp", "r", stdin);
		freopen("ss.out", "w", stdout);
	}
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		ans ^= x;
	}
	
	cout << ans << endl;
	return 0;
}

