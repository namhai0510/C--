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
const int maxa = 5e2 + 5;
const int base = 31;

ll L, R, dL, dR, a[maxn + 2], res, cL, cR;
vector<ll> D[15];

bool Check(ll n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(n); i += 2)
          if (n % i == 0) return false;
    
    return true;
}

int main() {
    nothing
    if (fopen("sprime.inp", "r")) {
        freopen("sprime.inp", "r", stdin);
        freopen("sprime.out", "w", stdout);
    }
	cin >> L >> R;
    L--;
    
    string l = to_string(L), r = to_string(R);
    dL = l.size();
    dR = r.size();
    a[1] = 10;
    for (int i = 2; i <= dR + 1; ++i) a[i] = a[i - 1] * 10;
    
    D[1] = {3, 5, 7};
    for (int k = 2; k <= dR + 1; ++k) {
        for (int i = 0; i < D[k - 1].size(); ++i) {
            for (int j = 1; j <= 9; ++j) {
                ll newval = j;
                newval *= a[k - 1];
                newval += D[k - 1][i];
                if (Check(newval)) D[k].pb(newval);
            }
        }
    }
    
    D[1].pb(2);
    for (int i = 1; i <= 10; ++i) sort(D[i].begin(), D[i].end());
    
    for (int i = 1; i< dL; ++i) cL += D[i].size();
    for (int i = 1; i< dR; ++i) cR += D[i].size();
    
    ll t = 0;
    t = lower_bound(D[dL].begin(), D[dL].end(), L) - D[dL].begin();
    cL += t;
    t = lower_bound(D[dR].begin(), D[dR].end(), R) - D[dR].begin();
    cR += t;
    
    cout << cR - cL;
    return 0;
}
