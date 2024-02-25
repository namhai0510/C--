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

ll n, f[maxn + 2], a[maxn + 2];
map<ll, ll> m;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	m[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    
    // for (int i = 1; i <= n; ++i) cout << a[i] << " " << m[a[i]] << endl;
    // cout << a[n] << endl;
    
    f[0] = 0; f[1] = m[1];
    
    for (int i = 2; i <= a[n]; ++i) {
    	f[i] = max(f[i - 1], f[i - 2] + m[i] * i);
    }
    
    // for (int i = 1; i <= n; ++i) cout << f[i] << endl;
    
    cout << f[a[n]] << endl;
    return 0;
}
// https://codeforces.com/problemset/problem/455/A
