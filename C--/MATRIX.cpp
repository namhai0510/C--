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

struct Matrix() {
    ll a[maxa][maxa];
    ll Size_1, Size_2;
    void Init(ll n, ll m) {
        Size_1 = n; Size_2 = m;
        memset(a, 0, sizeof(a));
    }
    
    void Set_0() {
        memset(a, 0, sizeof(a));
    }
    
    void print(ll n, ll m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

matran Product(Matrix A, Matrix B) {
    int m = A.Size_1, n = B.Size_2, p = B.Size_2;
    Matrix C;
    C.Set_0();
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < p; k++) {
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] % mod * B.a[k][j] % mod) % mod;
            }
        }
    }
    
    return C;
}

Matrix operator << (const Matrix &a, const ll x) {
	if (x == 1) return a;
	Matrix t = a << (x / 2);
	t = t * t;
	if (x & 1) t = t * a; 
	return t;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
}
