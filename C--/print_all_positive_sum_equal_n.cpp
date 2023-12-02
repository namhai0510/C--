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
const int maxn = 2e6 + 5;
const int maxa = 2e3 + 5;

ll n, a[maxn + 2];

void Re(ll it, ll val) {
	if (val == n) {
		for (int i = 1; i <= it - 1; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= n - val; ++i) {
		a[it] = i;
		Re(it + 1, val + i);
	}
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    Re(1, 0);
    return 0;
}
