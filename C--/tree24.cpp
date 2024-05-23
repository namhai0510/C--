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

ll n, a[maxn + 2];
ll zero = 0, one = 0, two = 0, res = +oo;
ll pfs0[maxn + 2], pfs1[maxn + 2], pfs2[maxn + 2];

bool Check(ll l, ll r) {
    if((pfs0[r] - pfs0[l - 1] >= zero) && (pfs1[r] - pfs1[l - 1] >= one) && (pfs2[r] - pfs2[l - 1] >= two)) return true;
    return false;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> zero >> one >> two;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        
        pfs0[i] = pfs0[i - 1];
        pfs1[i] = pfs1[i - 1];
        pfs2[i] = pfs2[i - 1];
        
        if (a[i] == 0) pfs0[i]++;
        if (a[i] == 1) pfs1[i]++;
        if (a[i] == 2) pfs2[i]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        ll l = i, r = n, mid, tmp = -1;
        
        while (l <= r) {
            mid = (l + r) / 2;
            if (Check(i, mid)) r = mid - 1, tmp = mid;
            else l = mid + 1;
        }
        
        if (tmp != - 1) res = min(res, tmp - i + 1);
    }
    
    if (res == +oo) res = -1;
    
    cout << res << endl;
    return 0;
}
