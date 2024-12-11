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

const double LOG2 = log10(2.0);
const double LOG3 = log10(3.0);

int n, m, res;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    double log2n = n * LOG2;
    double log3m = m * LOG3;

    double leadlog = max(log2n, log3m) + log10(1 + pow(10, -abs(log2n - log3m)));

    leadlog -= floor(leadlog); // Fractional part
    res = static_cast<int>(pow(10, leadlog));

    cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
