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

ll a, b, cnt = 0, st, en;

bool Prime(ll x) {
	if (x < 2) return 0;
	
	for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return 0;
    }
    
    return 1;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> a >> b;
    
    st = ceil(sqrt(a));
    en = floor(sqrt(b));
    
    for (int i = st; i <= en; ++i) {
    	if (Prime(i) && i * i <= b) cnt++;
    }
    
    cout << cnt << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
