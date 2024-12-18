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

ll a, b;
ll n, s = 0, x, j;

int main() {
    nothing
    if (fopen("UCDB.inp", "r")) {
        freopen("UCDB.inp", "r", stdin);
        freopen("UCDB.out", "w", stdout);
    }
    
    cin >> a >> b;
    
    x = a;
    j = b;
    
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    n = a;

    a = x;
    b = j;
    
    for (int i = 1; i <= sqrt(n); i++) {
        if (a % i == 0) {
            if (b % i == 0) {
                x = 0;
                j = i;
                while (j != 0) {
                    x = x + j % 10;
                    j = j / 10;
                }
                if (x > s) s = x;

                j = n / i;
                if (b % j == 0) {
                    x = 0;
                    while (j != 0) {
                        x = x + j % 10;
                        j = j / 10;
                    }
                    if (x > s) s = x;
                }
            }
        }
    }
    
    cout << s;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
