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
const ll modd = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 25 + 5;
const int base = 31;

ll n, a[maxn + 2], b[maxn + 2], c[maxa + 2][maxa + 2], w[maxa + 2][maxa + 2], cnt = 0;
vector<ll> order;

bool Check() {
	ll col, row;
	
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j) w[i][j] = -1;
    
    for (int k = 0; k < 2 * n; ++k) {
        if (order[k] < n) {
            row = order[k];
            for (int j = 0; j < n; ++j) {
                w[row][j] = a[row];}
        } 
        else {
            col = order[k] - n;
            for (int i = 0; i < n; ++i) w[i][col] = b[col];
        }
    
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (w[i][j] != c[i][j]) return 0;
            
    return 1;
}
int main() {
    nothing
    if (fopen("PAINT.inp", "r")) {
        freopen("PAINT.inp", "r", stdin);
        freopen("PAINT.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    for (int i = 0; i < n; ++i) cin >> b[i], --b[i];
    
    for (int i = 0; i < n; ++i) 
    	for (int j = 0; j < n; ++j) cin >> c[i][j], --c[i][j];
    	
    order.resize(2 * n);
    for (int i = 0; i < 2 * n; ++i) order[i] = i;
    
    do {
        if (Check()) cnt++;
    } while (next_permutation(order.begin(), order.end()));
    
    cout << cnt % modd;
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
