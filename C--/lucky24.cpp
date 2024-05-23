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
const int base = 31;

ll m, n, a[maxn + 2], res, tmp, k, Pow[63];

void Valid() {
    if(n > k / 2) {
        n -= k / 2;
        cout << 2;
    }
    else cout << 1;
}


int main() {
    nothing
    if (fopen("lucky.inp", "r")) {
        freopen("lucky.inp", "r", stdin);
        freopen("lucky.out", "w", stdout);
    }
    cin >> n;
    Pow[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        Pow[i] = Pow[i - 1] * 2;
    }
    
    for (int i = 1; i <= 60; ++i) {
        if (n - Pow[i] <= 0) {
            tmp = i;
            k = Pow[i];
            break;
        }
        n -= Pow[i];
    }
    
    if (n == 1) {
        for(int i = 1; i <= tmp; i++) cout << 1;
        exit(0);
    }

    while (k > 1) {
        Valid();
        k /= 2;
    }
    return 0;
}
