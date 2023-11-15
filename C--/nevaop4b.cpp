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

int main() {
    nothing
    if (fopen("nevaop4b.inp", "r")) {
        freopen("nevaop4b.inp", "r", stdin);
        freopen("nevaop4b.out", "w", stdout);
    }
    ll x, k;
	cin >> x >> k;
	
	ll dif = x % k;
    cout << (x / k) * k << endl << (x / k + dif) * k << endl;
    cout << (x / k + dif) * k - k << endl << (x / k + dif) * k + k << endl;
    
	return 0;
}