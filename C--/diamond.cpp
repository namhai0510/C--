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
const int maxa = 5e2 + 5;
const double eps = 1e-12;

ll n, k, a[maxn + 2], b[maxn + 2], A = 0, B = 0;
vector<pair<double, int>> val;
double l = 0.0, r = 1000000.0, sum = 0.0;

int main() {
    nothing
    if (fopen("diamond.inp", "r")) {
        freopen("diamond.inp", "r", stdin);
        freopen("diamond.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    // cout << A << " " << B << " " << eps << endl;
    
    while (r - l > eps) {
        double mid = (r + l) / 2;
        val.clear(); val.resize(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            val[i].fi = a[i] - mid * b[i];
            val[i].se = i;
        }
        sort(val.begin(), val.end());
        
        sum = 0.0;
        for (int i = n - k; i <= n; ++i) sum += val[i].fi;
        
        if (sum > (-1) * eps) {
            A = 0; B = 0;
            for (int i = n - k; i <= n; ++i) {
                A += a[val[i].se]; B += b[val[i].se];
            }
            l = mid;
        }
        else r = mid;
    }
    
    ll G = __gcd(A, B);
    A /= G; B /= G;
    // for (auto it : val) cout << it.fi << " " << it.se << endl; 
    
    cout << A << " " << B;
    return 0;
}
