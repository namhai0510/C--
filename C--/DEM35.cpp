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

ll test, n;

int main() {
    nothing
    if (fopen("DEM35.inp", "r")) {
        freopen("DEM35.inp", "r", stdin);
        freopen("DEM35.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	cout << n / 3 + n / 5 - n / 15 << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
