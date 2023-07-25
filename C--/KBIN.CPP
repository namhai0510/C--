#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll f[maxn];
int main() {
    nothing
    if (fopen("kbin.inp", "r")) {
        freopen("kbin.inp", "r", stdin);
        freopen("kbin.out", "w", stdout);
    }
    // Cho 2 s? n và k, xét các xâu nh? phân d? dài n mà không có 2 bit 1 nào k? nhau, tìm xâu th? k theo th? t? t? di?n
    ll n, k; cin >> n >> k;
    f[0] = 1; f[1] = 2; f[2] = 3; f[3] = 5;
    for (int i = 4; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    
    if (k > f[n]) {
        cout << "-1" << endl;
        // return 0;
    }
    else {
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (k > f[i]) {
                res = res + "1";
                k -= f[i];
            }
            else {
                res = res + "0";
            }
        }
        cout << res << endl;
        
    }
}



