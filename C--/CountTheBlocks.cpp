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
const ll modd = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n;
ll a[maxn + 2], P[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    a[1] = 10;
    P[0] = 1;
    for (int i = 1; i <= n; ++i) P[i] = (P[i - 1] * 10) % modd;
    for (int i = 2; i <= n; ++i) a[i] = (P[i - 2] * (81 * i + 18)) % modd;
    
    for (int i = n; i >= 1; --i) cout << a[i] << " ";
    
    return 0;
}
// https://codeforces.com/problemset/problem/1327/E
