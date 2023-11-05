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

ll n, i, f;

int main() {
    nothing
    if (fopen("parallel.inp", "r")) {
        freopen("parallel.inp", "r", stdin);
        freopen("parallel.out", "w", stdout);
    }
    cin >> n;
    
    for (int j = 1; j <= n; ++j) {
    	cin >> i >> f;
    	
    	if (i + f <= 3 && i < 3 && f < 3) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }
    return 0;
}
