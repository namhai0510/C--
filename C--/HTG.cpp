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

ll a[5], b[5];

int main() {
    nothing
    if (fopen("HTG.inp", "r")) {
        freopen("HTG.inp", "r", stdin);
        freopen("HTG.out", "w", stdout);
    }
    for (int i = 1; i <= 3; ++i) cin >> a[i];
    for (int i = 1; i <= 3; ++i) cin >> b[i];
    
    sort(a + 1, a + 4);
    sort(b + 1, b + 4);
    
    if (a[1] * a[1] + a[2] * a[2] != a[3] * a[3] ||
    	b[1] * b[1] + b[2] * b[2] != b[3] * b[3])
    	cout << -1 << endl;
    else if (a[1] == b[1]) cout << a[1] * a[2] << endl;
    else cout << -1 << endl;    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
