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

ll x[3], y[3];

int main() {
    nothing
    if (fopen("robot.inp", "r")) {
        freopen("robot.inp", "r", stdin);
        freopen("robot.out", "w", stdout);
    }
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    
    cout << max(abs(x[2] - x[1]), abs(y[2] - y[1]));

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/th_thpt_22_a