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

ll a, b;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> a >> b;
    
    if (a % 2 == 1) cout << 0;
    else if (b % 2 == 0) cout << 1; // a % 2 == 0 && b % 2 == 0
    else {
    	// a % 2 == 0 && b % 2 == 1
    	if (b > a / 2 && (b - a / 2) % 2 == 0) cout << 1;
    	else if (b < a / 2 && (a - 2 * b) % 2 == 0) cout << 1;
    	else cout << 0;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
