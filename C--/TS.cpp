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
const int maxn = 1e9;
const int maxa = 2e3;
const int base = 31;

ll n;

bool Prime(ll x) {
    if (x % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(x); i += 2)
        if (x % i == 0) return 0;
    
    return 1;
}

int main() {
    nothing
    if (fopen("TS.inp", "r")) {
        freopen("TS.inp", "r", stdin);
        freopen("TS.out", "w", stdout);
    }
    cin >> n;
    
    if (n % 2 == 0) n--;
    while (!Prime(n)) n -= 2;
    
    cout << n * 2 << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
