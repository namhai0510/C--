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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, a, b;

int main() {
    nothing
    if (fopen("bai1.inp", "r")) {
        freopen("bai1.inp", "r", stdin);
        freopen("bai1.out", "w", stdout);
    }
    cin >> n >> a >> b;
    
    if (a <= b) cout << 0;
    else cout << a - b;
    
    cout << " ";
    
    if (a + b <= n) cout << a;
    else cout << n - b;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/th_thpt_21_a
