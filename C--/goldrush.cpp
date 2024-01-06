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

ll t, n, m;

bool check(ll n, ll m) {
	if (n == m) return 1;
	else if (n % 3 != 0) return 0;
	else return (check(n / 3, m) || check(2 * n / 3, m));
}
int main() {
    nothing
    if (fopen("goldrush.inp", "r")) {
        freopen("goldrush.inp", "r", stdin);
        freopen("goldrush.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> m;
    	
    	if (check(n, m)) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    return 0;
}
