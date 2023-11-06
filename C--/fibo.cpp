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

ll n;
struct matran {
    ll a[2][2] = {{1, 1}, {1, 0}};
};

matran operator * (matran a, matran b) {
    matran c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.a[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
            }
        }
    }
    return c;
}

matran fibo(ll n) {
    matran c;
    if (n == 1) return c;
    matran t = fibo(n / 2);
    if (n % 2 == 1) return (t * t) * c;
    else return t * t;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    matran res = fibo(n - 1);
    cout << (res.a[0][0] + res.a[0][1]) % mod << endl;
}