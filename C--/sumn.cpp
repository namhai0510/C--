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

ll m, n, x, a[maxn], res, tmp, tmp2, original;
vector<ll> v;
map<ll, ll> cnt;

int main() {
    nothing
    if (fopen("sumn.inp", "r")) {
        freopen("sumn.inp", "r", stdin);
        freopen("sumn.out", "w", stdout);
    }
    cin >> n >> x >> m;
    
    original = x;
    tmp = x % m;

    while(1) {
        cnt[tmp]++;
        tmp = (tmp * tmp) % m;
        if(cnt[tmp] > 0) {
            v.pb(tmp);
            break;
        }
    }

    tmp2 = tmp;

    while(1) {
        tmp2 = tmp2 * tmp2 % m;
        if (tmp2 == tmp) break;
        else v.pb(tmp2);
    }

    ///for(auto it : v) cout << it << " ";

    while(x % m != v[0]) {
        res += x % m;
        x = x * x % m;
        n--;
    }

    for(int i = 0; i < v.size(); ++i) {
        a[i + 1] = a[i] + v[i];
    }

    ll cycles = n / v.size();
    ll extra = n % v.size();

    res += cycles * a[v.size()];
    res += a[extra];
    
    cout << res + original - original % m << endl;
    return 0;
}
